void setArm(int speed) //raise or lower arm
{
	motor[armRight] = speed;
	motor[armLeft] = speed;
}

void stopArm() //stop arm movement
{
	motor[armRight] = 0;
	motor[armLeft] = 0;
}

void drive(int leftSpeed, int rightSpeed) //move robot
{
	motor[leftFront] = leftSpeed;
	motor[leftBack] = leftSpeed;
	motor[rightFront] = rightSpeed;
	motor[rightBack] = rightSpeed;
}

void setClaw(int speed) //open or close claw
{
	motor[claw] = speed;
}

void stopClaw() //stop claw movement
{
	motor[claw] = 0;
}

//Author: Preethi
