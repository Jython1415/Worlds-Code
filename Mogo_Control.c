bool mogoCtrl_run = false;
bool mogoCtrl_done = false;

task mogoCtrl() {
    while (mogoCtrl_run == true && mogoCtrl_done == false) {
        //whatever works,
        //might need a setting to keep mogo in place
          //so for that when you use like
          //mogo(1000,0); for normal control and
          //mogo(1000,1); for it to not stop running until the main program tells it to
          //by setting mogoCtrl_run = false; In that mode it would just continue to run so the mogo is held at that position.
        
        wait1Msec(25);
    }
}
