//
// Created by boris on 18.10.16.
//

#include "Consumer.h"
#include <math.h>

Consumer::Consumer(unsigned int Pnominal, unsigned int Qnominal):
        Pnom(Pnominal), Qnom(Qnominal)
{
    Snom = sqrt (Pnominal*Pnominal + Qnominal*Qnominal);
}

void Consumer::calculate(std::chrono::milliseconds dTime) {
    double PnomCached = Pnom;
    double QnomCached = Qnom;
    double SnomCached = Snom;
    bool isConnectedCached = isConnected;
    if (isConnectedCached) {
        P = PnomCached;
        Q = QnomCached;
        S = SnomCached;
        AbstractElModel::calculatePowers();
        AbstractElModel::calculateCurrents();
    }
    else {
        AbstractElModel::resetParametersToZero();
    }
}

bool Consumer::connectToGRU() {
    return AbstractElModel::connectToGRU();
}

bool Consumer::disconnectToGRU() {
    return AbstractElModel::disconnectToGRU();
}
