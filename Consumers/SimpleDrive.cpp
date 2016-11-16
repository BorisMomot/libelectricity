//
// Created by boris on 01.11.16.
//

#include "SimpleDrive.h"
#include <math.h>

SimpleDrive::SimpleDrive(unsigned int Pnominal, unsigned int RPMnom, unsigned int Qnominal) : Consumer(Pnominal, Qnominal) {
    if (RPMnom > 0) {
        k = (double)Pnominal / RPMnom / RPMnom / RPMnom;
    }
    else {
        k = 0;
    }
}

void SimpleDrive::calculate(std::chrono::milliseconds dTime) {
    if (isConnected){
        RPM = targetRPM;
        computeDrivePowers();
        calculatePowers();
        calculateCurrents();
    }
    else {
        RPM = 0;
        resetParametersToZero();
    }
}

bool SimpleDrive::setRPM(int targetRPM) {
    if (isConnected){
        SimpleDrive::targetRPM = targetRPM;
        return true;
    }
    else {
        return false;
    }
}

void SimpleDrive::computeDrivePowers() {
    P = targetRPM * targetRPM * targetRPM * k;
}
