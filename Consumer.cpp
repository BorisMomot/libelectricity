//
// Created by boris on 18.10.16.
//

#include "Consumer.h"
#include <math.h>

Consumer::Consumer(unsigned int Pnominal, unsigned int Qnominal):
        Pnom(Pnominal), Qnom(Qnominal)
{
    Snom = sqrt (Pnom* Pnom + Qnom*Qnom);
}

void Consumer::calculate(unsigned int dTime)
{
    if (isConnected) {
        P = Pnom;
        Q = Qnom;
        S = Snom;
        calculatePowers();
        calculateCurrents();
    }
    else {
        resetParameterToZero();
    }
}