bool posDrive_run = false;
bool posDrive_done = false;
float kp_drive = 0.24;
float ki_drive = 0;
float kd_drive = 0.16;
float dT_drive;
float error_drive;
float preverror_drive;
float pwr_drive;
float integral_drive = 0;
float derivative_drive = 0;
float target_drive;
int driveMode = 0;

task posDrivePD() {
    while (posDrive_run == true && posDrive_done == false) {
        error_drive = target_drive - SensorValue[];
        derivative_drive = error_drive - preverror_drive;
        preverror_drive = error_drive;
        if(integral_drive > /*too much*/){
            ki_drive = 0;
        }
        else{
            integral_drive = integral_drive + error_drive;
        }

        pwr_arm = (error_drive*kp_drive) + (integral_drive*ki_drive) + (derivative_drive*kd_drive);
        setArm(pwr_drive);
        wait1Msec(25);

        if(abs(error_drive) < /*certain value*/ && driveMode = 0){
            posDrive_done = true;
        }
    }
}
//calculate auto straightening amount (put it into a variable using gyro & p value)
//add that amount from the right side
    //if adding that amount to the right side makes it greater than 127 then subtract it from the left side instead.
