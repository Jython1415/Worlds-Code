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

task armCtrl() {
    while (armCtrl_run == true && armCtrl_done == false) {
        error_arm = target_arm - SensorValue[arm_pot];
        integral_arm = integral_arm + error_arm;
        derivative_arm = error_arm - preverror_arm;
        preverror_arm = error_arm;

        pwr_arm = (error_arm*kp_arm) + (integral_arm*ki_arm) + (derivative_arm*kd_arm);
        setArm(pwr_arm);
          //arm(1000,0); for normal control and
          //arm(1000,1); for it to not stop running until the main program tells it to
        wait1Msec(25);
  }
}

void arm(float target_arm, int armMode){
    
}
