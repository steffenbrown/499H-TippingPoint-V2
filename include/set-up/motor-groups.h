using namespace vex;

#ifndef MOTORPAIR_H
#define MOTORPAIR_H
class motorPair {
  public:
    motor* motor1;
    motor* motor2;

    motorPair(motor* mot1, motor* mot2);
    void spin(directionType dir, double pow);
    void stop(brakeType brake);
};
#endif

extern motorPair Lift;
extern motorPair DriveLeft;
extern motorPair DriveRight;