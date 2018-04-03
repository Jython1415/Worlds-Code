bool posDrive_run = false;
bool posDrive_done = false;
float kp_drive = 0.24;
float ki_drive = 0;
float kd_drive = 0.16;
float kp_gyro = 0;
float dT_drive;
float multiplier_driver; //temporarily stores the number that derivative_drive is multiplied by
unsigned long lastTime;
float driveError;
float drivePreverror;
float driveIntegral = 0;
float driveDerivative = 0;
float gyroError;
float driveTarget;
float pwr_drive;

task posDrivePD() {
    SensorValue[gyro] = 0;
    while (posDrive_run == true && posDrive_done == false) {
        driveError = driveTarget - SensorValue[];
        driveDerivative = driveError - drivePreverror;
        drivePreverror = driveError;
        if(driveIntegral > /*too much*/){
            ki_drive = 0;
        }
        else{
            driveIntegral = driveIntegral + driveError;
        }
        gyroError = 0 + SensorValue[gyro];
        dT_drive = nPgmTime - lastTime; // Calculating time since last execution
        multiplier_driver = 25.0/dT_drive; // So that we find our actual rate of change.
        pwr_drive = (error_drive*kp_drive) + (integral_drive*ki_drive) + (derivative_drive*kd_drive*multiplier_driver);
        // made it so derivative term is also multiplied by multiplier
        
        if(gyroError > 10){
            if(abs(pwr_drive + (gyroError*kp_gyro)) > 127){
                setRight(pwr_drive - (gyroError*kp_gyro));
                setLeft(pwr_drive);
            }
            else if(abs(pwr_drive + (gyroError*kp_gyro)) < 127){
                setRight(pwr_drive);
                serLeft(pwr_drive + (gyroError*kp_gyro));
            }
        }
        else if(gyroError < -10){
            if(abs(pwr_drive + (gyroError*kp_gyro)) > 127){
                setRight(pwr_drive);
                setLeft(pwr_drive - (gyroError*kp_gyro));
            }
            else if(abs(pwr_drive + (gyroError*kp_gyro)) < 127){
                setRight(pwr_drive + (gyroError*kp_gyro));
                serLeft(pwr_drive);
            }
        }
        else{
            setRight(pwr_drive);
            setLeft(pwr_drive);
        }
        lastTime = nPgmTime; // I moved last time here so that I records the time when power was last set
        if(abs(driveError) < /*certain value*/){
            posDrive_done = true;
        }
        wait1Msec(25);
    }
}
//calculate auto straightening amount (put it into a variable using gyro & p value)
//add that amount from the right side
    //if adding that amount to the right side makes it greater than 127 then subtract it from the left side instead.
