/**
 * @file charoit_abstract.c
 * @author Lockie (k303278@126.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-27 15:02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "charoit_abstract.h"


motor_st motor;

void motor_init()
{
    motor.direction = 0.0f;
    motor.angular_velocity = 0.0f;
    motor.linear_velocity = 0.0f;
}