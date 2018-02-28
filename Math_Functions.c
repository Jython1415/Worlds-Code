int constrain(int value, int lowerBound, int upperBound) {
	value = (value > upperBound) ? upperBound : (value < lowerBound) ? lowerBound : value;
	return value;
}

int correctedGyroAngle(int gyroAngle) {
	gyroAngle = (gyroAngle < 0) ? gyroAngle + 3600 : gyroAngle;
	return(gyroAngle);
}