#include "vex.h"

void usercontrol() {
  while(true) {
    arcadeControl(&DriveLeft, &DriveRight, &controllerMain);
    liftManualControl(&Lift, &controllerMain.ButtonL1, &controllerMain.ButtonL2);
    

    task::sleep(20);
  }
}