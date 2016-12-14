//
// Created by boris on 18.10.16.
//

#include "Source.h"
#include <math.h>


Source::Source(double Pnominal, double Qnominal, double Unominal):
        Pnom(fabs(Pnominal)), Qnom(fabs(Qnominal)), Unom(fabs(Unominal))
{
    Snom = sqrt(Pnom*Pnom + Qnom*Qnom);
    double UnomCached = Unom;
    targetU = UnomCached;
    internalRcalculator = new RintCalculator(Pnominal, Unominal);
}

void Source::calculate(std::chrono::milliseconds dTime) {
    calculatePowers();
    calculateCurrents();
    Rinternal = internalRcalculator->computeRinternal(dTime, P, targetF, f); //расчитываем внутреннее сопротивление источника
}

bool Source::stopSource() {
    bool isConnectedCached = isConnected;
    if (!isConnectedCached) {
        isStarted = false;
        return true;
    }
    else {
        return false;
    }
}

bool Source::setF(unsigned int frequency) {
    bool isStartedCached = isStarted;
    if (isStartedCached) {
        f = frequency;
        return true;
    }
    else {
        f = 0;
        return false;
    }
}

bool Source::setU(unsigned int voltage) {
    bool isStartedCached = isStarted;
    if (isStartedCached) {
        U = voltage;
        Ua = voltage;
        Ub = voltage;
        Uc = voltage;
        return true;
    }
    else {
        U = 0;
        Ua = 0;
        Ub = 0;
        Uc = 0;
        return false;
    }
}

bool Source::increaseTargetVoltage(unsigned int voltageStep) {
    bool isStartedCached = isStarted;
    double targetUCached = targetU;
    if (isStartedCached) {
        targetU = targetUCached + voltageStep;
        return true;
    }
    else {
        return false;
    }
}

bool Source::decreaseTargetVoltage(unsigned int voltageStep) {
    bool isStartedCached = isStarted;
    double targetUCached = targetU;
    if (isStartedCached && ( (targetUCached - voltageStep) > 0 ) ) {
        targetU = targetUCached - voltageStep;
        return true;
    }
    else {
        return false;
    }
}

bool Source::connectToGRU() {
    if (isStarted && U > 0) {
        isConnected = true;
        return true;
    }
    else {
        return false;
    }
}


Source::~Source(){}

bool Source::increaseTargetFrequency(unsigned int frequencyStep) {
    bool isStartedCached = isStarted;
    double targetFCached = targetF;
    if (isStartedCached) {
        targetF = targetFCached + frequencyStep;
        return true;
    }
    else {
        return false;
    }
}

bool Source::decreaseTargetFrequency(unsigned int frequencyStep) {
    bool isStartedCached = isStarted;
    double targetFCached = targetF;
    if (isStartedCached && ( (targetFCached - frequencyStep) > 0)) {
        targetF = targetFCached - frequencyStep;
        return true;
    }
    else {
        return false;
    }
}

bool Source::setRCalculator(RintCalculator *Rcalc) {
    if (Rcalc != nullptr) {
        internalRcalculator = Rcalc;
        return true;
    }
    else {
        return false;
    }
}

void Source::computeSourceU(std::chrono::milliseconds dTime) {
    double targetUCached = targetU;
    U = Ua = Ub = Uc = targetUCached;
}

void Source::computeSourceF(std::chrono::milliseconds dTime) {
    double targetUCached = targetU;
    U = Ua = Ub = Uc = targetUCached;
}

double Source::computeRinternal(std::chrono::milliseconds dTime) {
    Rinternal = internalRcalculator->computeRinternal(dTime, P, targetF, f);
    return Rinternal;
}
