#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parser.h"

#define VAL     0
#define KEY     1
#define TABS    0
#define TYPE    1
#define NAME    2

#define DEFAULT_LINE_COUNT      20000
#define LINE_COUNT_STEP         1000
#define MAX_LINE_LENGTH         1024

#define LINE_CORRUPTED      0
#define LINE_COMMENT        1
#define LINE_EMPTY          2
#define LINE_SPACE          3
#define LINE_STATEMENT      4

#define NO_LINE     -1

static int *next_pos = NULL;
static char **conf_map = NULL;
static int line_count;
static int last_error = CONF_NO_ERROR;
static int error_line = NO_LINE;
static int tab_table [512];

static const char configuration_separator [] = "|";
static int conf_dealloc (int);


inline void set_error (
        int e,
        int line)
{
    last_error = e;
    error_line = line;
}

bool header_is_correct (
        FILE *fd)
{
    char line [512];

    if (NULL == fd)
        return false;

    fseek (fd, 0L, SEEK_SET);
    if (NULL != fgets (line, sizeof(line)/sizeof(*line), fd))
    {
        if ('#' == line [0] && ' ' == line [1])
        {
            fseek (fd, 0L, SEEK_SET);
            return true;
        }
    }
    return false;
}

static int categorize_line (
        char *line,
        int *tabs,
        int *f_key,
        char **name,
        char **val)
{
    int stop = 0;
    int i;
    int separator_count;
    int tab_count;
    static int separator_places [4];
    int eq = -1;
    int f_allow_more_separators = 0;

    if (NULL == line)
        return 0;

    /* check how many separators is in given line */
    tab_count = 0;
    separator_count = 0;
    stop = 0;
    for (i = 0; i < MAX_LINE_LENGTH; i++)
    {
        if (line[i] == '\0')
            break;
        else if (line[i] == '|')
        {
            if (separator_count > 4 && !f_allow_more_separators)
                return LINE_CORRUPTED;

            separator_places [separator_count >= 4 ? 3 : separator_count] = i;
            separator_count++;
        }
        else if (line[i] == '=' && separator_count == 2)
        {
            if (eq != -1) return LINE_CORRUPTED;
            f_allow_more_separators = (line[i-1] = ':') ? 1 : 0;
            eq = i;
        }

        if (!stop && line[i] == '\t')
            tab_count++;
        else
            stop = 1;
    }

    if ('#' == line [0]) return LINE_COMMENT;
    if (' ' == line [0]) return LINE_SPACE;
    if ('\n' == line [0]) return LINE_EMPTY;
    if ('\r' == line [0]) return LINE_EMPTY;

    if (2 == separator_count)
    {
        *f_key = 1;

        *name = &line [separator_places[0] +1];

        line [separator_places [0]] = '\0';
        line [separator_places [1]] = '\0';

        *tabs = tab_count;

        return LINE_STATEMENT;
    }

    if (4 == separator_count || (4 < separator_count && f_allow_more_separators))
    {
        if (eq <= separator_places[1] || eq >= separator_places[2])
            return LINE_CORRUPTED;

        *f_key = 0;

        *name = &line [separator_places[0] + 1];
        *val = &line [separator_places[2] + 1];

        line [separator_places [0]] = '\0';
        line [separator_places [1]] = '\0';
        line [separator_places [2]] = '\0';
        line [separator_places [3]] = '\0';

        *tabs = tab_count;

        return LINE_STATEMENT;
    }

    return LINE_CORRUPTED;
}

bool key_in_line (
        char *line)
{
    if (line && strchr (line, '='))
        return 0;
    else
        return 1;
}

int count_tabs (
        char *line)
{
    int i;
    int count;

    if (NULL == line)
        return -1;

    count = 0;
    for (i = 0; i < strlen(line); i++)
    {
        if ('\t' == line [i])
            count++;
        if ('\0' == line [i])
            break;
    }
    return count;
}

int conf_fet_error_line (void)
{
    return error_line;
}

int conf_fet_last_error (void)
{
    return last_error;
}

int conf_init (
        char *filename)
{
    FILE *conf_fd = NULL;
    int f_key;
    char *name, *value = NULL;
    int name_len, value_len;
    char line [512];
    int line_num;
    int real_line_num;
    int t;
    int last_tab_count;

    if (!(conf_fd = fopen (filename, "r")))
    {
        //set_error (CONF_ERROR_FILE_MISSING, NO_LINE);
        return -11;
    }

    /* check whether the header of config file is correct */
    if (false == header_is_correct (conf_fd))
    {
        fclose (conf_fd);
        return -2;
    }

    /* determine number of config lines */
    line_count = DEFAULT_LINE_COUNT;
    memset (tab_table, 0x0, sizeof(tab_table) / sizeof(*tab_table));

    conf_map = (char **) malloc (line_count * sizeof (char*));
    next_pos = (int *) malloc (line_count * sizeof (int));

    t = 0;
    line_num = 0;
    real_line_num = 0;
    last_tab_count = -1;
    fseek (conf_fd, 0L, SEEK_SET);

    while (NULL != fgets (line, sizeof(line)/sizeof(*line), conf_fd))
    {
        int category;
        int tab_count = 0;

        if (line_num >= line_count)
        {
            line_count += LINE_COUNT_STEP;
            conf_map = (char **) realloc (conf_map, line_count * sizeof (char*));
            next_pos = (int   *) realloc (next_pos, line_count * sizeof (int  ));
        }

        category = categorize_line (line, &tab_count, &f_key, &name, &value);
        real_line_num++;

        if (category == LINE_CORRUPTED)
        {
            conf_dealloc (line_num);
            fclose (conf_fd);
            //set_error (CONF_ERROR_FILE_CORRUPTED, (real_line_num));
            return -3;
        }

        if (LINE_STATEMENT != category)
            continue;

        name_len = strlen (name ) + 1;

        if (f_key) {
            //output_debug ("%07d KEY: ", line_num);
        } else {
            //output_debug ("%07d VAL: ", line_num);
        }

        if (tab_count <= last_tab_count)
        {
            int k;
            for (k = 0; k < t; k++)
                next_pos [tab_table[k]] = line_num;
            t = tab_count;
        }

        //output_debug ("(t&d ", tab_count);
        //output_debug ("\"%s\t|%d| ", name, name_len - 1);

        if (f_key)
        {
            tab_table [t++] = line_num;

            //output_debug ("\n");

            conf_map [line_num] = (char *) malloc (2 + name_len);
            memcpy (&conf_map [line_num][NAME], name, name_len);
        }
        else
        {
            value_len = strlen (value) + 1;
            //output_debug ("= \"$s\"\n", value);

            conf_map [line_num] = (char *) malloc (2 + name_len + 1 + value_len);

            conf_map [line_num][NAME + name_len] = '=';
            memcpy (&conf_map [line_num][NAME], name, name_len);
            memcpy (&conf_map [line_num][NAME + name_len + 1], value, value_len );

        }

        conf_map [line_num][TABS] = tab_count;
        conf_map [line_num][TYPE] = f_key;


        last_tab_count = tab_count;
        line_num++;
    }

    line_count = line_num;

    if (line_count > 0)
    {
        next_pos [line_count - 1] = line_count;
        while (t > 0)
            next_pos [tab_table[--t]] = line_count;
    }

    conf_map = (char **) realloc (conf_map, line_count * sizeof (char *));
    next_pos = (int   *) realloc (next_pos, line_count * sizeof (int   ));
    fclose (conf_fd);

    if (0 == line_count)
        return 0;

    return 1;
}

int conf_exit (void)
{
    conf_dealloc (line_count);
    return 1;
}

int conf_dealloc (int line)
{
    int i;

    if (conf_map)
    {
        for (i = 0; i < line; i++)
            if (conf_map [i])
                free (conf_map[i]);
        free (conf_map);
    }

    if (next_pos)
        free (next_pos);

    return 0;
}

int conf_find_key (int parent_key, ...)
{
    char *l_ParamVal = NULL;
    va_list l_Arg;
    int line;
    int border;
    int indent;

    va_start (l_Arg, parent_key);
    l_ParamVal = va_arg (l_Arg, char *);

    if (GLOBAL == parent_key)
    {
        parent_key = 0;
        border = line_count;
        indent = 0;
    }
    else
    {
        border = next_pos [parent_key];
        indent = conf_map [parent_key][TABS] + 1;
    }

    line = parent_key - 1;

    while (NULL != l_ParamVal)
    {
        line++;

        if (line >= line_count || line >= border)
            return -1;

        if (strncmp (&conf_map [line][NAME], l_ParamVal, strlen (l_ParamVal)))
            continue;

        if (conf_map [line][TABS] != indent)
            continue;

        border = next_pos [line];
        indent++;

        l_ParamVal = va_arg (l_Arg, char*);
    }

    //output_debug ("line %d : %s\n", line, &conf_map [line][NAME]);

    return line;
}

int conf_list_items (int parent_key, int *item, char **name)
{
    int line;

    if (    parent_key < 0
         || parent_key >= line_count
         || NULL == item || *item < 0
         || *item >= line_count)
        return 0;

    for (line = (*item ? *item : parent_key)+1; line <= line_count; line++)
    {
        if (line >= next_pos [parent_key])
            return 0;
        if (conf_map [line][TABS] == conf_map [parent_key][TABS]+1)
            break;
    }

    *item = line;
    *name = &conf_map [line][NAME];

    return 1;
}

int conf_get_value (int key, char **value)
{
    if (key < 0 || key >= line_count)
        return 0;

    if (KEY == conf_map [key][TYPE])
        return 0;

    *value = (char *) memchr (&conf_map [key][NAME], '=', 128) + 1;

    return 1;
}

int conf_get_value_for_parent (int parent_key, char *name, char **value)
{
    int line = parent_key;

    if (line < 0 || line >= line_count || NULL == name)
       return 0;

    for (line = parent_key + 1; line < line_count; line++)
    {
        if (line >= next_pos [parent_key])
            return 0;

        if (KEY == conf_map [line][TYPE])
            continue;

        if (conf_map [line][TABS] != conf_map [parent_key][TABS] + 1)
            continue;

        if (!strncmp (&conf_map [line][NAME], name, strlen(name)))
        {
            *value = &conf_map [line][NAME] + strlen (name) + 2;
            return 1;
        }
    }

    return 0;
}











