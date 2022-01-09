#include "vex.h"

using namespace vex;

competition Competition = competition();

brain Brain;

controller controllerMain = controller();
controller controllerSecondary = controller();

motor LiftLeft = motor(PORT1, gearSetting::ratio6_1, false);
motor LiftRight = motor(PORT2, gearSetting::ratio6_1, false);

motor DriveLeftBack = motor(PORT3, gearSetting::ratio18_1, false);
motor DriveLeftFront = motor(PORT4, gearSetting::ratio18_1, false);
motor DriveRightBack = motor(PORT5, gearSetting::ratio18_1, false);
motor DriveRightFront = motor(PORT6, gearSetting::ratio18_1, false);
encoder EncoderDriveLeft = encoder(Brain.ThreeWirePort.C);
encoder EncoderDriveRight = encoder(Brain.ThreeWirePort.E);

motor elevator = motor(PORT7, gearSetting::ratio18_1, false);

motor picklift = motor(PORT8, gearSetting::ratio6_1);

pneumatics pickliftLatch = pneumatics(Brain.ThreeWirePort.A);
pneumatics pickLatch = pneumatics(Brain.ThreeWirePort.B);

void pre_auton(void) {
  
}