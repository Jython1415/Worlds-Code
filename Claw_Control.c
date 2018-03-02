bool clawCtrl_run = false; // this variable is used by the main function to let the task know when it's supposed to run
                           // and when it should stop. the task shouldn't mess with this variable, just read it so it knows
                           // when to run and stuff
bool clawCtrl_done = false;// this variable is used by the task to let the main function know when it is done. tasks that will
													 // be for holding something in place (like arm holding in place for grabbing) should use some other
													 // variable for that specific task because the done bool is also used for the task to determine
													 // when to exit the loop and end control.

void startClawCtrl() { // the function used when we program the route. my idea would be to have a vaiable for open/close be the input
	startTask(clawCtrl);
}

task clawCtrl() {
  while (clawCtrl_run == true && clawCtrl_done == false) { // while main function says run and we aren't done yet
		
		//calculate power to send to motors
		
		//set motor power
			// setPower(power, port);
			// setDrive(power); - You define function like this if you need it at the top of your document.
    
    //set clawCtrl_done = true; if you've reduced error to within your MoE (or if you've finished what your task needs to do)
			//remember, if it's a holding in place kinda thing like claw or arm then don't set this to true. 
		
    wait1Msec(25); // At some point on the forums jpearman recommended this wait time for loops
                   // because of motor controller refresh rates and other factors
  }
}
