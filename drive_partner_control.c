#pragma config(Motor,  port1,           armLeftTop,    tmotorNone, openLoop)
#pragma config(Motor,  port3,           rightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           armLeft,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           armRightTop,   tmotorNone, openLoop)
#pragma config(Motor,  port10,          armRight,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "drive.h"

task main()
{

	//declare constants
	int CLAW_SPEED = 127;
	int DEADBAND = 10;

	//create variables
	float leftSpeed = 0;
	float rightSpeed = 0;
	float armSpeed = 0;
	int openClaw = 0;
	int closeClaw = 0;


	//drive

	while(true)
	{
		//set variables
		leftSpeed = vexRT[Ch3];
		rightSpeed = vexRT[Ch2];
		armSpeed = vexRT[Ch3Xmtr2];
		openClaw = vexRT[Btn5UXmtr2];
		closeClaw = vexRT[Btn5DXmtr2];


		//1st controller


		//left deadband
		if (abs(leftSpeed) < DEADBAND)
		{
			leftSpeed = 0;
		}

		// right deadband
		if (abs(rightSpeed) < DEADBAND)
		{
			rightSpeed = 0;
		}

		//drive robot
		drive(leftSpeed, rightSpeed);


		//2nd controller


		//move arm

		//deadband
		if (abs(armSpeed) < DEADBAND)
		{
			armSpeed = 0;
		}

		setArm(armSpeed);

		//move claw

		if(openClaw == 1) // open claw with button 5U
		{
			setClaw(CLAW_SPEED);
		}
		else if(closeClaw == 1) //close claw with button 5D
		{
			setClaw(-CLAW_SPEED);
		}
		else
		{
			stopClaw();
		}
	}

}

//Author: Preethi
