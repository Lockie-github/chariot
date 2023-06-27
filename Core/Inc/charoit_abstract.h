#ifndef __CHARIOT_ABSTRACT_H__
#define __CHARIOT_ABSTRACT_H__

#include "main.h"
#include "float.h"


typedef struct
{
    int8_t direction ;
    float angular_velocity ;
    float linear_velocity ;

}motor_st;

void motor_init(void);
extern motor_st motor;




#endif