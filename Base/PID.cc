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

double PID::computeOutput(std::chrono::milliseconds dTime, double error) {
	double output;
    //кэшируемся, для потоко безопасности
    double integrMismatchCached = integrMismatch;
    double KpCached = Kp;
    double TiCached = Ti;
	//защищаемся от переполнения
	if (fabs(integrMismatchCached) < 1e300){
		if (fabs(error) < 1e200) {
			double t = integrMismatchCached + error;
            integrMismatchCached = t;
		}
	}
	else {
		if (!signbit(integrMismatchCached)) {
            integrMismatchCached = 1e300;
		}
		else {
            integrMismatchCached = -1e300;
		}
	}
	if (TiCached != 0) {
		output = KpCached * error + 1/TiCached * KpCached * dTime.count() * integrMismatchCached;
	}
	else {
		output = -1;
	}
    integrMismatch = integrMismatchCached;
	return output;
}


