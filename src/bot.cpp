#include "bot.h"
#include "util.h"

Controller CONTROLLER = Controller(E_CONTROLLER_MASTER);
Motor CATAPULT(4);
Motor INTAKE(8);
Motor DESCORER(7);
Motor LEFT_BASE_1(10);
Motor LEFT_BASE_2(3);
Motor RIGHT_BASE_1(9);
Motor RIGHT_BASE_2(2);
bool autonReverse = false;
ADIDigitalIn ARM_LIM_SWITCH('A');

std::int32_t canalog(controller_analog_e_t channel) {
  return CONTROLLER.get_analog(channel);
}

std::int32_t cdigital(controller_digital_e_t button) {
  return CONTROLLER.get_digital(button);
}

std::int8_t buttons(controller_digital_e_t button1, controller_digital_e_t button2) {
  return cdigital(button1) ? 1 : (cdigital(button2) ? -1 : 0);
}

void drive(std::int8_t left, std::int8_t right) {
  if(autonReverse) {
    std::int8_t oldLeft = left;
    left = right;
    right = oldLeft;
  }
  std::int8_t l = threshold(-left, DRIVE_THRESHOLD);
  std::int8_t r = threshold(right, DRIVE_THRESHOLD);
  LEFT_BASE_1 = l;
  LEFT_BASE_2 = -l;
  RIGHT_BASE_1 = r;
  RIGHT_BASE_2 = -r;
}

void drive_dist(double left, double right, std::int32_t velmx) {
  if(autonReverse) {
    double oldLeft = left;
    left = right;
    right = oldLeft;
  }
  LEFT_BASE_1.move_absolute(LEFT_BASE_1.get_position() - left, velmx);
  LEFT_BASE_2.move_absolute(LEFT_BASE_2.get_position() + left, velmx);
  RIGHT_BASE_1.move_absolute(RIGHT_BASE_1.get_position() + right, velmx);
  RIGHT_BASE_2.move_absolute(RIGHT_BASE_2.get_position() - right, velmx);
}

void auton_reverse() {
  autonReverse = !autonReverse;
}

void descorer(std::int8_t speed) {
  DESCORER = speed;
}

void intake(std::int8_t speed) {
  INTAKE = speed;
}

void catapult(std::int8_t speed) {
  CATAPULT = -speed;
}

std::int32_t get_arm_lim_switch() {
  return ARM_LIM_SWITCH.get_value();
}
