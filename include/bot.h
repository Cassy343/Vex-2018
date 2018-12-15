#ifndef _BOT_H_
#define _BOT_H_

#include "prosincl.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DRIVE_THRESHOLD 20

#define DESCORER_DOWN 0
#define DESCORER_HOVER -40
#define DESCORER_UP -150

extern Controller CONTROLLER;
extern Motor PUNCHER;
extern Motor INTAKE;
extern Motor DESCORER;
extern Motor LEFT_BASE_1;
extern Motor LEFT_BASE_2;
extern Motor RIGHT_BASE_1;
extern Motor RIGHT_BASE_2;

std::int32_t canalog(controller_analog_e_t);
std::int32_t cdigital(controller_digital_e_t);
std::int8_t buttons(controller_digital_e_t, controller_digital_e_t);
void drive(std::int8_t, std::int8_t);
void drive_dist(double, double, std::int32_t=127);
void reverse_drive();
void auton_reverse();
void descorer(std::int8_t);
void intake(std::int8_t);
void catapult(std::int8_t);
std::int32_t get_arm_lim_switch();

#ifdef __cplusplus
}
#endif

#endif
