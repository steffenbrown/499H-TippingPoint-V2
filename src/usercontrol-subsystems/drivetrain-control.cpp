#include "vex.h"

void arcadeControl(motorPair* chassisLeft, motorPair* chassisRight, controller* control) {
  chassisLeft->spin(forward, control->Axis3.position() + control->Axis1.position());
  chassisRight->spin(forward, control->Axis3.position() - control->Axis1.position());
}