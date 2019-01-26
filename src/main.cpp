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
    drive_dist(0, 350, 75);
    delay(2000);
    drive_dist(2000, 2000);
    delay(2000);
    drive_dist(-5100, -5100);
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

void auton3(bool blue) {
  while(!get_arm_lim_switch()) {
    catapult(127);
  }
  delay(250);
  catapult(0);

  drive_dist(2600, 2600);
  intake(-127);
  delay(2000);

  if(blue) {
    drive_dist(-2400, -2400);
    delay(2000);
    drive_dist(650, -650);
    delay(1500);
    catapult(127);
    delay(500);
    drive_dist(2000,2200);
    delay(800);
    catapult(0);
    delay(700);
    drive_dist(1200,1400);
    delay(1000);
    drive_dist(-4900,-4900);
    delay(3500);
    drive_dist(-650, 650);
    delay(800);
    intake(0);
    drive_dist(2500, 2500);
  }else{
    drive_dist(-2600, -2600);
    delay(2000);
    drive_dist(-650, 650);
    delay(1500);
    catapult(127);
    delay(500);
    drive_dist(3200,3200);
    delay(800);
    catapult(0);
    delay(1700);
    drive_dist(-4900,-4900);
    delay(3500);
    drive_dist(650, -650);
    delay(800);
    intake(0);
    drive_dist(3000, 3000);
  }
}

void auton4(bool blue){
  while(!get_arm_lim_switch()) {
    catapult(127);
  }
  catapult(0);
  delay(8000);
  catapult(127);
  delay(500);
  catapult(0);
  if(blue)
  {
    drive_dist(-300,300);
    delay(1000);
    drive_dist(2000,2000);
    delay(2000);
    drive_dist(600,-600);
    delay(1000);
    drive_dist(2700,2700);
  }
  else
  {
    drive_dist(300,-300);
    delay(1000);
    drive_dist(2000,2000);
    delay(2000);
    drive_dist(-600,600);
    delay(1000);
    drive_dist(2700,2700);
  }
}

void auton5(bool blue)
{
  drive_dist(-1300,-1300);
  delay(3500);
  if(blue){
  drive_dist(-650, 650);
  }
  else{
    drive_dist(650,-650);
  }
  delay(800);
  drive_dist(3400, 3400);
}

void auton6(bool blue) {
  while(!get_arm_lim_switch()) {
    catapult(127);
  }
  delay(250);
  catapult(0);

  drive_dist(2600, 2600);
  intake(-127);
  delay(2000);

  if(blue) {
    drive_dist(-2400, -2400);
    delay(2000);
    drive_dist(700, -700);
    delay(1500);
    catapult(127);
    delay(500);
    drive_dist(3200,3200);
    delay(800);
    catapult(0);
    delay(1700);
    drive_dist(-3200,-3200);

  }else{
    drive_dist(-2600, -2600);
    delay(2000);
    drive_dist(-650, 650);
    delay(1500);
    catapult(127);
    delay(500);
    drive_dist(3200,3200);
    delay(800);
    catapult(0);
    delay(1700);
    drive_dist(-3200,-3200);

  }
}


void auton_skills(){
  auton3(false);
  drive_dist(1600, 1600);
}

void autonomous() {
  bool blue = true;
/*
  Auton 1 is outdated.
  Auton 2 is outdated.
  Auton 3 is the double shot and platform climb
  Auton 4 is the snipe auton
  Auton 5 is the park from the back auton
  Auton 6 is double shot with zero-single-double shot follow-up
*/
  //auton1(false);
  auton3(blue);
  //auton4(blue);
  //auton_skills();
  //auton5(false);
  /*if(get_auton() == 1) {
    return;
  }

  std::int32_t ra = rev_auton();
  if(ra) {
    auton_reverse();
  }

  if(get_auton() == 3) {
  drive_dist(5000, 5000);
  intake(127);
  delay(5000);
  intake(0);
  return;
}*/
/*
  drive_dist(1000, 1000);
  catapult(127);
  delay(2000);

  catapult(0);
  drive_dist(300, 0, 75);
  delay(2000);

  drive_dist(2000, 2000);
  delay(2000);

  drive_dist(2000, 2000);
  catapult_dist(1200);
  intake(127);
  delay(3000);
  drive_dist(-2000,-2000);
  delay(2000);

  // Red addendum

  drive_dist(-4700, -4700);
  delay(5000);
  drive_dist(650, -650);
  delay(1000);
  drive_dist(3500, 3500);
  /*/

  // Blue addendum
  /*
  drive_dist(-4950, -4950);
  delay(5000);
  drive_dist(-650, 650);
  delay(1000);
  drive_dist(3000, 3000);

  drive_dist(650,-650);
  delay(2000);
  catapult_dist(3000);
  delay(2000);
  //

  if(ra) {
    auton_reverse();
  }*/
}

void initialize() {

}

void disabled() {

}

void competition_initialize() {

}

void opcontrol() {
  bool driveReverseButton = false;
  while(true) {
    drive(canalog(ANALOG_LEFT_Y), canalog(ANALOG_RIGHT_Y));
    descorer(-buttons(DIGITAL_X, DIGITAL_B) * 127);
    intake(-buttons(DIGITAL_R1, DIGITAL_R2) * -127);
    catapult(cdigital(DIGITAL_L1) * 127);
    /*if(!CATAPULT_LIMIT.get_value()){
      catapult(127);
    }
    else if(CATAPULT_LIMIT.get_value()){
      catapult(0);
    }*/
  }
}
