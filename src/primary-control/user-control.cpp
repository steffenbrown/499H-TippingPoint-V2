#include "vex.h"

void usercontrol() {
  while(true) {
    arcadeControl(&DriveLeft, &DriveRight, &controllerMain);

    task::sleep(20);
  }
}