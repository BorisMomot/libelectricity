
#include "DG.h"
#include <math.h>

DG::DG(unsigned int Pnominal, unsigned int Qnominal, unsigned int Unominal) : Source(Pnominal, Qnominal, Unominal), pi(0, 1)
{
    computeJ();
}

void DG::computeSourceF(std::chrono::milliseconds dTime) {
	Source::computeSourceF(dTime);

    computeFuelFlow(dTime);
    computeMdv(dTime);
    computeMnagr(dTime);
    computeRPM(dTime);
    f = RPM / 60;
}

void DG::computeJ() {
    J = (Pnom/314) * (Pnom/314)/20;
}

void DG::computeFuelFlow(std::chrono::milliseconds dTime) {
    FuelFlow_ps = FuelFlow;
    FuelFlow = pi.computeOutput(dTime, (targetF - f));
}

void DG::computeMdv(std::chrono::milliseconds dTime) {
    Mdv_ps = Mdv;
    Mdv = ( FuelFlow*dTime.count() + Mdv_ps*0.5 )/ (0.5 + dTime.count());
}

void DG::computeMnagr(std::chrono::milliseconds dTime) {
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

void DG::computeRPM(std::chrono::milliseconds dTime) {
    RPM_ps = RPM;
    RPM = RPM_ps + (Mdv - Mnagr)/J * dTime.count() *60/2/M_PI;
}


