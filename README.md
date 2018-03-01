# Worlds-Code
	For managing our code for worlds bot

	Abbreviations:
		I tend to shorten mogo lift to just mogo so hopefully that doesn't confuse you
		MoE = margin of error
		vel = velocity
	 	pos = position, usually could mean the encoder value of the sensor attached to the arm/wheel
	 	rot = rotation or angle
		pwr = power, the motor power input

	Goals:
	  When we program for the autonomous routine I want it to be so that we can just use these functions and it would run.
	  	velDrive(int posTarget, int rotTarget, int velTarget) {}
	  	posDrive(int posTarget, int rotTarget, int MoE) {}
			mogo(int posTarget, int mode) {}
			arm(int posTarget, int mode) {}
			claw() {} // I dunno how we could want this to work yet
	
		I want it to be so that when we set power we use function
			setPower(int power, int port) {}
			
			We can combine so that it's easier for certain things.
				setDrive(int pwr) {
					setPower(pwr, FRONT_LEFT_MOTOR);
					setPower(pwr, BACK_LEFT_MOTOR);
					setPower(pwr, FRONT_RIGHT_MOTOR);
					setPower(pwr, BACK_RIGHT_MOTOR);
				}
				
			The setPower function would use an array that makes power to rpm relation linear
				https://docs.google.com/spreadsheets/d/13x8a7H3O3LsVOiK3bTbOEOiYsXpDXGmv9VnEylI1J2A/edit#gid=0
				Link for motor mapping spreadsheet I developed over summer.
				
				setPower(int pwr, int port) {
					switch (port) {
						case 1 :
							motor[port1] = motorMappingArray[pwr];
							break;
						case 2 :
							motor[port2] = motorMappingArray[pwr];
							break;
						case 3 :
							motor[port3] = motorMappingArray[pwr];
							break;
						case 4 :
							motor[port4] = motorMappingArray[pwr];
							break;
						case 5 :
							motor[port5] = motorMappingArray[pwr];
							break;
						case 6 :
							motor[port6] = motorMappingArray[pwr];
							break;
						case 7 :
							motor[port7] = motorMappingArray[pwr];
							break;
						case 8 :
							motor[port8] = motorMappingArray[pwr];
							break;
						case 9 :
							motor[port9] = motorMappingArray[pwr];
							break;
						case 10 :
							motor[port10] = motorMappingArray[pwr];
							break;
						default :
							writeDebugStreamLine("Motor power request for invalid port number: %d", pgmTime);
					}
				}
	
