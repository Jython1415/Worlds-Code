bool armCtrl_run = false;
bool armCtrl_done = false;

task armCtrl() {
  while (armCtrl_run == true && armCtrl_done == false) {
    //whatever works,
        //might need a setting to keep arm in place
          //so for that when you use like
          //arm(1000,0); for normal control and
          //arm(1000,1); for it to not stop running until the main program tells it to
          //by setting armCtrl_run = false; In that mode it would just continue to run so the arm is held at that position.
    
    wait1Msec(25);  
  }
}
