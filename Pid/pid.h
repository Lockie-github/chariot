#ifndef __PID_H
#define __PID_H

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct 
{
    float target_val;
    float actual_val;
    float err;
    float err_last;
    float err_next;
    float kp,ki,kd;
}pid_st;








#endif