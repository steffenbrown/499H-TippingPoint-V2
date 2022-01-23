#include "vex.h"

///////////////////////////////////////////////////////////////////////////

motorPair* lift;
bool abortCorrection;

int correctionTask() {
  const double tolerance = 3;
  double leftLiftRotation, rightLiftRotation;

  while(!abortCorrection) {
    leftLiftRotation = lift->motor1->position(rotationUnits::deg);
    rightLiftRotation = lift->motor2->position(rotationUnits::deg);
    
    if(leftLiftRotation - tolerance > rightLiftRotation) {
      lift->motor2->spin(forward, 100, velocityUnits::pct);
    } else if(rightLiftRotation - tolerance > leftLiftRotation) {
      lift->motor1->spin(forward, 100, velocityUnits::pct);
    } else {
      lift->stop(hold);
      break;
    }
    task::sleep(20);
  }
  return 0;
}


void correct(motorPair* lif) {
  lift = lif;
  abortCorrection = false;
  task automaticLiftCorrectionTask(correctionTask);
}
void cancelCorrection() {
  abortCorrection = true;
}

///////////////////////////////////////////////////////////////////////////


void liftManualControl(motorPair* lift, controller::button* upButton, controller::button* downButton) {
  bool postMove = false;
  
  if(downButton->pressing()) {
    cancelCorrection();
    lift->spin(forward, 100);
    postMove = true;
  } else if(upButton->pressing()) {
    cancelCorrection();
    lift->spin(forward, 30);
    postMove = true;
  } else {
    if(postMove) {
      correct(lift);
      postMove = false;
    } else {
      lift->stop(hold);
    }
  }
}