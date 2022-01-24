using namespace vex;

extern competition Competition;

extern brain Brain;

extern controller controllerMain;
extern controller controllerSecondary;

extern motor LiftLeft;
extern motor LiftRight;

extern motor DriveLeftBack;
extern motor DriveLeftFront;
extern motor DriveRightBack;
extern motor DriveRightFront;
extern encoder EncoderDriveLeft;
extern encoder EncoderDriveRight;

extern motor elevator;

extern motor picklift;

extern digital_out pickliftLatch;
extern digital_out liftLatch;

void pre_auton(void);
