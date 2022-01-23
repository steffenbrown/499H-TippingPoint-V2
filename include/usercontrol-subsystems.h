#include "set-up/motor-groups.h"

void arcadeControl(motorPair* chassisLeft, motorPair* chassisRight, controller* control);

void liftManualControl(motorPair* lift, controller::button* upButton, controller::button* downButton);

void intakeManualControl(motor* intake, controller::button* forwardButton, controller::button* reverseButton);
void intakeToggleControl(motor* intake, controller::button* toggleButton, controller::button* reverseButton);

void pickliftPIDControl(motor* lif, controller::button* up, controller::button* down, double targPos, double p, double i, double d);
void pickliftManualControl(motor* lift, controller::button* upButton, controller::button* downButton);
