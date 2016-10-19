//
// Created by boris on 18.10.16.
//

#include "Consumer.h"
#include <math.h>

Consumer::Consumer(unsigned int Pnominal, unsigned int Qnominal):
        Pnom(Pnominal), Qnom(Qnominal)
{
    Snom = sqrt (Pnominal* Pnominal + Qnominal*Qnominal);
}

void Consumer::calculate(unsigned int dTime)
{
    P = Pnom;
    Q = Qnom;
    S = Snom;
    calculatePowers();
    calculateCurrents();
}