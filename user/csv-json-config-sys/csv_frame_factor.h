#ifndef SUB_NAVI_CFG_CSV_FRAME_FACTOR_H
#define SUB_NAVI_CFG_CSV_FRAME_FACTOR_H

#include "navi-config.h"

enum frame_factor_col
{
    FRAME_FACTOR_COL_ROLL,
    FRAME_FACTOR_COL_PITCH,
    FRAME_FACTOR_COL_YAW,
    FRAME_FACTOR_COL_THROTTLE,
    FRAME_FACTOR_COL_FORWARD,
    FRAME_FACTOR_COL_LATERAL,
    FRAME_FACTOR_COL_MAX,
};

enum frame_factor_row
{
    FRAME_FACTOR_ROW_MOTOR_0,
    FRAME_FACTOR_ROW_MOTOR_1,
    FRAME_FACTOR_ROW_MOTOR_2,
    FRAME_FACTOR_ROW_MOTOR_3,
    FRAME_FACTOR_ROW_MOTOR_4,
    FRAME_FACTOR_ROW_MOTOR_5,
#if SUB_NAVI_CONFIG_USE_EIGHT_THRUSTERS
    FRAME_FACTOR_ROW_MOTOR_6,
    FRAME_FACTOR_ROW_MOTOR_7,
#endif
    FRAME_FACTOR_ROW_MAX,
};

typedef struct
{
    float value[FRAME_FACTOR_ROW_MAX][FRAME_FACTOR_COL_MAX]; // row --, col |
} frame_factor_t;

frame_factor_t *frame_factor_get_from_file(const char *config_file_path);

#endif