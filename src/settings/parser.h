/**
 *
 * \brief
 *
 * This is the header file of parser which allows to read and save
 * the configuration file
 *
 * \author Karol Siegieda
 *
 * \version 1.0
 *
 * \date 2018/09/13 14:16:20
 *
 * Contact: karolsiegied@gmail.com
 *
 */
#ifndef PARSER_H
#define PARSER_H

#define GLOBAL  -1

#ifdef  __cplusplus
extern "C" {
#endif

#define CONF_NO_ERROR                   0
#define CONF_ERROR_FILE_CORRUPTED       1
#define CONF_ERROR_FILE_MISSING         2

/**
 * @brief conf_get_error_line - Function returns error line number
 * @return if value is smaller than 0 there is no error line
 */
int conf_get_error_line (void);

/**
 * @brief conf_get_last_error - Function returns last error code
 * @return if 0, there is no error code
 */
int conf_get_last_error (void);

/**
 * @brief conf_init - Function load config file to memory
 * @return 1 if success, and 0 if error
 */
int conf_init (
        char *filename);

/**
 * @brief conf_exit - Function release memory for config file
 * @return if value is different than 0 then success
 */
int conf_exit (void);

/**
 * @brief conf_find_key - Function search given key in configuration
 * @param parent_key - is the parent (higher level) key from given. If GLOBAL is set, then all
 * config file is searched
 * @return return address of key or -1 if no found
 */
int conf_find_key (
        int parent_key,
        ...);

/**
 * @brief conf_list_items - Function that lists all the keys in range of given key
 * @param parent_key - key, for which other keys are searched
 * @param item - is address of found key (previous, next). Value in beggining should be 0
 * @param name - is the pointer to name of found key
 * @return returns 1 if success or 0 if no more keys
 */
int conf_list_items (
        int parent_key,
        int *item,
        char **name);

/**
 * @brief conf_get_value - Function that returns value of searched key
 * @param key - key, for which value is searched
 * @param value - pointer to key chain with value of given key
 * @return returns  0 is key has no assigned value and 1 is value had been found
 */
int conf_get_value (
       int key,
        char **value);

/**
 * @brief conf_get_value_for_parent - Function that returns value (if exists) of key with given name
 * @param parent_key - key, for which other keys are searched
 * @param name - name of sarched key
 * @param value - pointer to key chain with value of given key
 * @return returns 0 is there is no key with given name (or without assigned value) or 1 if found
 */
int conf_get_value_for_parent (
        int parent_key,
        char *name,
        char **value);
#ifdef __cplusplus
}
#endif

#endif
