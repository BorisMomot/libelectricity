//
// Created by boris on 19.10.16.
//

#include "RintCalculator.h"

RintCalculator::RintCalculator(unsigned int Pnominal, unsigned int Unominal, double EfficiencyNominal,
                               unsigned int Kkonstractional):
Pnom(Pnominal), Unom(Unominal), Kkonstr(Kkonstractional)
{
    if (EfficiencyNominal <= 1 && EfficiencyNominal > 0) {
        EfficiencyNom = EfficiencyNominal;
    }
    else {
        EfficiencyNom = 0.98;
    }
}

double RintCalculator::calculateRinternal(unsigned int dTime, double Pcurrent, double Ftarget, double Fcurrent, double Pkr) {
    double R, sinFi;
    sinFi = calculatesinFi(dTime, Pcurrent, Ftarget, Fcurrent, Pkr);
    R = static_cast<double>(Unom)*static_cast<double>(Unom)*EfficiencyNom/(1-EfficiencyNom)/Pnom + Kkonstr*sinFi/Pnom;
    return R;
}
double RintCalculator::calculatesinFi(unsigned int dTime, double Pcurrent, double Ftarget, double Fcurrent, double Pkr) {
    if (Pkr < Pnom || Pkr <= 0) {
        return Pcurrent/(Pnom*4) - (Ftarget - Fcurrent)*dTime/1000; //принимаем по дефолту, что критическая мощность в 4 раза больше номинальной
    }
    else {
        return Pcurrent/Pkr - (Ftarget - Fcurrent)*dTime/1000;
    }
}
