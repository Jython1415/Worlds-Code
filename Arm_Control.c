bool armCtrl_run = false;
bool armCtrl_done = false;
float kp_arm = 0.24;
float ki_arm = 0;
float kd_arm = 0.16;
float dT_arm;
float armError;
float armPreverror;
float pwr_arm;
float armIntegral = 0;
float armDerivative = 0;
float armTarget;
int armMode = 0;

task armCtrl() {
    while (armCtrl_run == true && armCtrl_done == false) {
        armError = armTarget - SensorValue[arm_pot];
        armDerivative = armError - armPreverror;
        armPreverror = armError;
        
        if(armIntegral > /*too much*/){
            ki_arm = 0;
        }
        else{
            armIntegral = armIntegral + armError;
        }

        pwr_arm = (armError*kp_arm) + (armIntegral*ki_arm) + (armDerivative*kd_arm);
        setArm(pwr_arm);
        wait1Msec(25);
        if(abs(armError) < /*certain value*/ && armMode = 0){
            armCtrl_done = true;
        }
    }
    while (armCtrl_run == false && armCtrl_done == false){
        armError = armTarget - SensorValue[arm_pot];
        armIntegral = armIntegral + armError;
        armDerivative = armError - armPreverror;
        armPreverror = armError;

        arm_pwr = (armError*armKp) + (armIntegral*armKi) + (armDerivative*armKd);

        if(armError!=0){
          setArm(arm_pwr);
        }
        else{
          setArm(0);
        }
    }
}

void arm(float aim, int Mode){
    armTarget = aim;
    armMode = Mode;
    startTask(armCtrl);
    //arm(1000,0); for normal control and
    //arm(1000,1); for it to not stop running until the main program tells it to
}
