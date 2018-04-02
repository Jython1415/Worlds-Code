bool armCtrl_run = false;
bool armCtrl_done = false;
float kp_arm = 0.24;
float ki_arm = 0;
float kd_arm = 0.16;
float dT_arm;
float error_arm;
float preverror_arm;
float pwr_arm;
float integral_arm = 0;
float derivative_arm = 0;
float target_arm;
int armMode = 0;

task armCtrl() {
    while (armCtrl_run == true && armCtrl_done == false) {
        error_arm = target_arm - SensorValue[arm_pot];
        derivative_arm = error_arm - preverror_arm;
        preverror_arm = error_arm;
        if(integral_arm > /*too much*/){
            ki_arm = 0;
        }
        else{
            integral_arm = integral_arm + error_arm;
        }

        pwr_arm = (error_arm*kp_arm) + (integral_arm*ki_arm) + (derivative_arm*kd_arm);
        setArm(pwr_arm);
        wait1Msec(25);

        if(abs(error_arm) < /*certain value*/ && armMode = 0){
            armCtrl_done = true;
        }
    }
}

void arm(float aim, int Mode){
    target_arm = aim;
    armMode = Mode;
    startTask(armCtrl);
    //arm(1000,0); for normal control and
    //arm(1000,1); for it to not stop running until the main program tells it to
}
