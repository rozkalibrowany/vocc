#ifndef PARAMETERS
#define PARAMETERS

#define MAX_RPM_VALUE           6000
#define ANGLE_RANGE             245.0
#define DEFAULT_BACKG_COLOR     24
#define PYTHON_CMD              "python"
#define SIMULATION_FILE         "can_simulation.py"
#define RUN_CAN_CMD             "stdbuff -o0 candump can0"
#define CAN_INIT                "ip link set can0 up type can bitrate"
#define MESSAGE_1               "0CF11E05"
#define MESSAGE_2               "0CF11F05"
#define DEFAULT_FONT            "Halvetica"
#define SHUTDOWN_CMD            "shutdown now"

#endif // PARAMETERS

