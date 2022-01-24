#include "vex.h"

void usercontrol() {
  while(true) {
    arcadeControl(&DriveLeft, &DriveRight, &controllerMain);

    if(!controllerSecondary.installed()) {
      liftManualControl(&Lift, &controllerMain.ButtonL1, &controllerMain.ButtonL2);
      pickliftManualControl(&picklift, &controllerMain.ButtonR1, &controllerMain.ButtonR2);
      intakeToggleControl(&elevator, &controllerMain.ButtonA, &controllerMain.ButtonB);
      liftLatchControl(&liftLatch, &controllerMain.ButtonUp);
    } else {

    }
    
    task::sleep(20);
  }
}