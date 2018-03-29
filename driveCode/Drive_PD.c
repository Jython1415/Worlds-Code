bool posDrive_run = false;
bool posDrive_done = false;

task posDrivePID() {
	while (posDrive_run == true && posDrive_done == false) {
		//calculate base speed using PID
			//tune the constants however you want. there are some great explanations online
			//what I tend to do is put the p value so that it barely doesn't make it
			//and then use the i value as a way to have a minimum adjustment value so that
			//it gets the last bit
			
			//actual pid would be so that you raise the p value until you have a steadily
			//decreasing oscillation. then put in d to subtract power which makes the whole
			//thing smoother. in this case the i term would be optional to decrease error
			//to zero towards the very end.
		
		//calculate auto straightening amount (put it into a variable using gyro & p value)
		
		//add that amount from the right side
			//if adding that amount to the right side makes it greater than 127 then subtract
			//it from the left side instead.
		
		//set power
		
		//check to see if you've reached the destination (set posDrive_done = true if it's done)
	
		wait1Msec(25);
	}
}
