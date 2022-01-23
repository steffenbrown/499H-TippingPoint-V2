#include "vex.h"

bool userControllerPeripheralsActive = false;
bool autoControllerPeripheralsActive = false;
bool partnerControlActive;

controller* controllerPrimary;
controller* contollerSecondary;


int userControlControllerScreenTask() {
  autoControllerPeripheralsActive = false;
  userControllerPeripheralsActive = true;

  while(userControllerPeripheralsActive) {
    if(!partnerControlActive) {
      controllerPrimary->Screen.clearScreen();
      controllerPrimary->Screen.setCursor(0, 1);
      controllerPrimary->Screen.print("Mode: Solo");
    } else {

    }

    task::sleep(50);
  }
  return 0;
}

void userControlControllerScreenPeripherals(controller* control) {
  if(!userControllerPeripheralsActive) {
    partnerControlActive = false;
    controllerPrimary = control;
    task userControllerPeripheral(userControlControllerScreenTask);
  }
}

void userControlControllerScreenPeripherals(controller* controlP, controller* controlS) {
  if(!userControllerPeripheralsActive) {
    partnerControlActive = false;
    controllerPrimary = controlP;
    contollerSecondary = controlS;
    task userControllerPeripheral(userControlControllerScreenTask);
  }
}