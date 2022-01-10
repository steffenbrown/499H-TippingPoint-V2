#include "vex.h"
using namespace vex;

//motorPair Class
motorPair::motorPair(motor* mot1, motor* mot2) {
  motor1 = mot1;
  motor2 = mot2;
}

void motorPair::spin(directionType dir, double pow) {
  motor1->spin(dir, pow, velocityUnits::pct);
  motor2->spin(dir, pow, velocityUnits::pct);
}

void motorPair::stop(brakeType brake) {
  motor1->stop(brake);
  motor2->stop(brake);
}
//End of motorPair class

motorPair Lift = motorPair(&LiftLeft, &LiftRight);
motorPair DriveLeft = motorPair(&DriveLeftBack, &DriveLeftFront);
motorPair DriveRight = motorPair(&DriveRightBack, &DriveRightFront);
