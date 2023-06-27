#include "pid.h"

pid_st pid;
/**
 * @brief 
 * 
 * @param p 
 * @param i 
 * @param d 
 */
void pid_init(float p, float i, float d)
{
    pid.kp = p;
    pid.ki = i;
    pid.kd = d;
    pid.actual_val = 0;
    pid.target_val = 0;
    pid.err = 0;
    pid.err_last = 0;
    pid.err_next = 0;
}

void set_pid_param(float p,float i,float d)
{
    pid.kp = p;
    pid.ki = i;
    pid.kd = d;
}

void set_target_val(float val)
{
    pid.target_val = val;
}

void get_target_val(float val)
{
    return pid.target_val;
}

float pid_realize( float actual_val)
{
    pid.err = pid.target_val - pid.actual_val;
    pid.actual_val += pid.kp*(pid.err - pid.err_next) 
                    + pid.ki*pid.err 
                    + pid.kd*(pid.err - 2 * pid.err_next + pid.err_last);
    pid.err_last = pid.err_next;
    pid.err_next = pid.err;
    return pid.actual_val;
}