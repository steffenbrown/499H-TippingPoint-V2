#include "vex.h"

///////////////////////////////////////////////////////////////////////////

void intakeManualControl(motor* intake, controller::button* forwardButton, controller::button* reverseButton) {
  if(forwardButton->pressing()) {
    intake->spin(forward, 100, percentUnits::pct);
  } else if(reverseButton->pressing()) {
    intake->spin(reverse, 80, percentUnits::pct);
  } else {
    intake->stop(brake);
  }
}

///////////////////////////////////////////////////////////////////////////

motor* toggleableIntake;
bool intakeToggled = false;
bool intakeReversing = false;

void toggleIntake() {
  if(!intakeReversing) {
    if(intakeToggled) {
      toggleableIntake->stop(brakeType::coast);
    } else {
      toggleableIntake->spin(forward, 100, percentUnits::pct);
    }
  }
}

void intakeToggleControl(motor* intake, controller::button* toggleButton, controller::button* reverseButton) {
  toggleableIntake = intake;

  if(reverseButton->pressing()) {
    intakeReversing = true;
    intake->spin(reverse, 80, percentUnits::pct);
  } else {
    intakeReversing = false;
  }

  toggleButton->pressed(toggleIntake);
}

///////////////////////////////////////////////////////////////////////////