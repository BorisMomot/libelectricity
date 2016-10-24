
#include "DG.h"
#include <math.h>

DG::DG(unsigned int Pnominal, unsigned int Qnominal, unsigned int Unominal) : Source(Pnominal, Qnominal, Unominal)
{
    computeJ();
}

void DG::calculateSourceF(unsigned int dTime) {
    Source::calculateSourceF(dTime);


    computeFuelFlow(dTime);
    computeMdv(dTime);
    computeMnagr(dTime);
    computeRPM(dTime);
    f = RPM / 60;
}

void DG::computeJ() {
    J = (Pnom/314) * (Pnom/314)/20;
}

void DG::computeFuelFlow(unsigned int dTime) {
    FuelFlow_ps = FuelFlow;
    //защищаемся от переполнения
    if (fabs(integrMismatch) < 1e300){
        if ((fabs(f) < 1e200) && fabs(targetF) < 1e200) {
            integrMismatch += (targetF - f);
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
        FuelFlow = Kp * (targetF - f) + 1/Ti * Kp * dTime * integrMismatch;
    }
    else {
        FuelFlow = -1;
    }
}

void DG::computeMdv(unsigned int dTime) {
    Mdv_ps = Mdv;
    Mdv = ( FuelFlow*dTime + Mdv_ps*0.5 )/ (0.5 + dTime);
}

void DG::computeMnagr(unsigned int dTime) {
    Mnagr = P / (f*2);
}

void DG::computeRPM(unsigned int dTime) {
    RPM_ps = RPM;
    RPM = RPM_ps + (Mdv - Mnagr)/J * dTime *60/2/M_PI;
}


