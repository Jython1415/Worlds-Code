#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl9,  button,         sensorTouch)
#pragma config(Sensor, I2C_1,  integratedDriveRight, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  integratedDriveLeft, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  integratedMogo, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           ML,            tmotorVex393_HBridge, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port2,           LF1,           tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port3,           RF1,           tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port4,           RF2,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RB,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LF2,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LB,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          MR,            tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

/* -||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||- */

#include "Math_Functions.c"
#include "setPower_Functions.c"

/* -||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||- */

void pre_auton() {
  bStopTasksBetweenModes = true;
	bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/* -||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||- */

#include "Velocity_Drive_PID.c"
#include "Position_Drive_PID.c"
#include "Turn_PID.c"
#include "Mogo_Control.c"
#include "Arm_Control.c"
#include "Claw_Control.c"

/* -||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||- */

task autonomous() {

}

task usercontrol() {

}
