#include "main.h"
#include "bot.h"

void auton1(bool blue) {
  while(!get_arm_lim_switch()) {
    catapult(127);
  }
  catapult(0);
  delay(500);
  catapult(127);
  delay(500);
  catapult(0);

  drive_dist(1300, 1300);
  delay(1800);

  if(blue) {
    drive_dist(2000, 2000);
    delay(2000);
    drive_dist(-4950, -4950);
    delay(5000);
    drive_dist(-650, 650);
    delay(1000);
    drive_dist(3400, 3400);
  }else{
    drive_dist(0, 300, 75);
    delay(2000);
    drive_dist(2000, 2000);
    delay(2000);
    drive_dist(-4900, -4900);
    delay(5000);
    drive_dist(650, -650);
    delay(1000);
    drive_dist(3500, 3500);
  }
}

void auton2(bool blue) {
  intake(127);
  drive_dist(2800, 2800);
  delay(2300);

  intake(0);
  drive_dist(-350, -350);
  delay(700);
  drive_dist(650, -650);
  delay(1000);

  drive_dist(4000, 4000);
  delay(4200);

  intake(127);
  delay(1600);
  intake(0);

  drive_dist(-90, 90);
  delay(500);

  while(!get_arm_lim_switch()) {
    catapult(127);
  }
  catapult(0);
  delay(1000);
  catapult(127);
  delay(1000);
  catapult(0);

  drive_dist(-2000, -2000);
  delay(1400);
}

void autonomous() {
  bool blue = true;

  auton1(blue);
  //auton2(blue);
}

void initialize() {

}

void disabled() {

}

void competition_initialize() {

}

void opcontrol() {
  bool driveReverseButton = false;
  int armTicks = 0;
  while(true) {
    drive(canalog(ANALOG_LEFT_Y), canalog(ANALOG_RIGHT_Y));
    descorer(-buttons(DIGITAL_X, DIGITAL_B) * 127);
    intake(-buttons(DIGITAL_R1, DIGITAL_R2) * 127);
    catapult(cdigital(DIGITAL_L1) * 127);
  }
}
