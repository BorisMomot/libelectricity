//
// Created by boris on 10/25/16.
//

#include "PID.h"
#include <math.h>

PID::PID(double Kp, double Ti) {
	PID::Kp = Kp;
	PID::Ti = Ti;
}

double PID::getKp() const {
	return Kp;
}

bool PID::setKp(double Kp) {
	PID::Kp = Kp;
	return true;
}

double PID::getTi() const {
	return Ti;
}

bool PID::setTi(double Ti) {
	if( Ti > 0) {
		PID::Ti = Ti;
		return true;
	}
	else {
		return false;
	}
}

double PID::computeOutput(unsigned int dTime, double error) {
	double output;
	//защищаемся от переполнения
	if (fabs(integrMismatch) < 1e300){
		if (fabs(error) < 1e200) {
			integrMismatch += error;
		}
	}
	else {
		if (!signbit(integrMismatch)) {
			integrMismatch = 1e300;
		}
		else {
			integrMismatch = -1e300;
		}
	}
	if (Ti != 0) {
		output = Kp * error + 1/Ti * Kp * dTime * integrMismatch;
	}
	else {
		output = -1;
	}
	return output;
}


