#pragma config(Motor,  port3,           rightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           armLeft,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           armRight,      tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	short leftSpeed;
	short rightSpeed;
	short armSpeed;
	short clawSpeed;

	while(true)
	{
		//left side
		if (vexRT[Ch3] > -15 && vexRT[Ch3] < 15) {
			leftSpeed = 0;
		}
		else {
			leftSpeed = vexRT[Ch3];
		}

		//right side
		if (vexRT[Ch2] > -15 && vexRT[Ch2] < 15) {
			rightSpeed = 0;
		}

		else {
			rightSpeed = vexRT[Ch2];
		}

		//arm
		if (vexRT[Btn6U] == 1){
			armSpeed = 100;
		}
		else if (vexRT[Btn6D] == 1){
			armSpeed = -100;
		}
		else {
			armSpeed = 0;
		}

		//claw
		if (vexRT[Btn5U] == 1){
			armSpeed = 100;
		}
		else if (vexRT[Btn5D] == 1){
			armSpeed = -100;
		}
		else {
			armSpeed = 0;
		}


	}
	motor[rightFront] = rightSpeed;
	motor[rightBack] = rightSpeed;
	motor[leftFront] = leftSpeed;
	motor[leftBack] = leftSpeed;
	motor[armRight] = armSpeed;
	motor[armLeft] = armSpeed;
	motor[claw] = clawSpeed;



}
