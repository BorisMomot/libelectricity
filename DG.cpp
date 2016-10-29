
#include "DG.h"
#include <math.h>

DG::DG(unsigned int Pnominal, unsigned int Qnominal, unsigned int Unominal) : Source(Pnominal, Qnominal, Unominal), pi(0, 1)
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
    FuelFlow = pi.computeOutput(dTime, (targetF - f));
}

void DG::computeMdv(unsigned int dTime) {
    Mdv_ps = Mdv;
    Mdv = ( FuelFlow*dTime + Mdv_ps*0.5 )/ (0.5 + dTime);
}

void DG::computeMnagr(unsigned int dTime) {
    if (P!=0) {
        if (f!=0){
            Mnagr = P / (f*2); //формула по которой считаем при корректных значениях
        }
        else {
            Mnagr = 0;
        }
    }
    else {
        Mnagr = 0;
    }
}

void DG::computeRPM(unsigned int dTime) {
    RPM_ps = RPM;
    RPM = RPM_ps + (Mdv - Mnagr)/J * dTime *60/2/M_PI;
}


