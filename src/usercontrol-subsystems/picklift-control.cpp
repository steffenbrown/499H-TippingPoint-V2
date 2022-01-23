#include "vex.h"

///////////////////////////////////////////////////////////////////////////

void pickliftManualControl(motor* lift, controller::button* upButton, controller::button* downButton) {
  if(upButton->pressing()) {
    lift->spin(forward, 80, percentUnits::pct);
  } else if(downButton->pressing()) {
    lift->spin(reverse, 50, percentUnits::pct);
  } else {
    lift->stop(hold);
  }
}

///////////////////////////////////////////////////////////////////////////

bool abortPIDLiftTask;
motor* PIDpicklift;
controller::button* upButton;
controller::button* downButton;
directionType direct;
double Kp, Ki, Kd, error, lastError, integral, derivative, targetPosition, motorPower;

static int PIDPickLiftTask() {
  lastError = 0;
  integral = 0;

  while(!abortPIDLiftTask && (error < 3 && error > -3) && derivative < 1) {
    error = PIDpicklift->position(rotationUnits::deg) - targetPosition;
    derivative = error - lastError;
    integral += error;

    motorPower = error * Kp + derivative * Kd + integral * Ki;

    PIDpicklift->spin(forward, motorPower, percentUnits::pct);
    task::sleep(20);
  }
  return 0;
}

static void cancelMovement() {
  abortPIDLiftTask = true;
}

static void liftUp() {
  cancelMovement();
  task::sleep(25);
  abortPIDLiftTask = false;
  direct = forward;
  task automaticPIDPickLiftTask(PIDPickLiftTask);
}

static void liftDown() {
  cancelMovement();
  task::sleep(25);
  abortPIDLiftTask = false;
  direct = reverse;
  task automaticPIDPickLiftTask(PIDPickLiftTask);
}

void pickliftPIDControl(motor* lif, controller::button* up, controller::button* down, double targPos, double p, double i, double d) {
  Kp = p;
  Ki = i;
  Kd = d;
  PIDpicklift = lif;
  upButton = up;
  downButton = down;
  targetPosition = targPos;

  up->pressed(liftUp);
  down->pressed(liftDown);
}

///////////////////////////////////////////////////////////////////////////