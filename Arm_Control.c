bool armCtrl_run = false;
bool armCtrl_done = false;
float kp_arm = 0;
float ki_arm = 0;
float kd_arm = 0;
float dT;
float arm_error;
float arm_preverror
float arm_pwr;
float arm_integral = 0;
float arm_derivative = 0;
float target;

task armCtrl() {
    while (armCtrl_run == true && armCtrl_done == false) {
        arm_error = target - SensorValue[arm_pot];
        arm_integral = arm_integral + arm_error;
        arm_derivative = arm_error - arm_preverror;
        arm_preverror = arm_error;

        arm_pwr = (error*kp_arm) + (arm_integral*ki_arm) + (arm_derivative*kd_arm);
        setPower(arm_pwr,6);
        //might need a setting to keep arm in place
          //so for that when you use like
          //arm(1000,0); for normal control and
          //arm(1000,1); for it to not stop running until the main program tells it to
          //by setting armCtrl_run = false; In that mode it would just continue to run so the arm is held at that position.   
    wait1Msec(25);  
  }
}
