#include "vex.h"

void raiseLift(motorPair* lift) {
  lift->spin(forward, 100);
}

void lowerLift(motorPair* lift) {
  lift->spin(reverse, 20);
}

class automaticLiftCorrection {
  private:
    static motorPair* lift;

    static int correctionTask() {
      const double tolerance = 5;
      double leftLiftRotation, rightLiftRotation;

      while(true) {
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

  public:
    static void correct(motorPair* lif) {
      lift = lif;
      task automaticLiftCorrectionTask(automaticLiftCorrection);
    }
};

void liftManualControl(motorPair* lift, controller::button* upButton, controller::button* downButton) {
  bool postMove = false;
  
  if(downButton->pressing()) {
    raiseLift(lift);
  } else if(upButton->pressing()) {
    lowerLift(lift);
  } else {
    if(postMove) {
      automaticLiftCorrection::correct(lift);
    } else {
      lift->stop(hold);
    }
  }
}