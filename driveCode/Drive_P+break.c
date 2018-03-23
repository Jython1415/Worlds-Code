bool velDrive_run = false;
bool velDrive_done = false;

task velDrivePID() {
		while (velDrive_run == true && velDrive_done == false) {
		//An idea I had for fast movement that doesn't have to be as precise
		
		wait1Msec(25);
	}
}
