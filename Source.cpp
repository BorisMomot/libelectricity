//
// Created by boris on 18.10.16.
//

#include "Source.h"
#include <math.h>


Source::Source(double Pnominal, double Qnominal, double Unominal):
        Pnom(fabs(Pnominal)), Qnom(fabs(Qnominal)), Unom(fabs(Unominal))
{
    Snom = sqrt(Pnom*Pnom + Qnom*Qnom);
    targetU = Unom;
    internalRcalculator = new RintCalculator(Pnominal, Unominal);
}

void Source::calculate(std::chrono::milliseconds dTime)
{
    calculatePowers();
    calculateCurrents();
    Rinternal = internalRcalculator->calculateRinternal(dTime, P, targetF, f); //расчитываем внутреннее сопротивление источника
}

bool Source::stopSource()
{
    if (!isConnected)
    {
        isStarted = false;
        return true;
    }
    else
    {
        return false;
    }
}

bool Source::setF(unsigned int frequency)
{
    if (isStarted)
    {
        f = frequency;
        return true;
    }
    else
    {
        f = 0;
        return false;
    }
}

bool Source::setU(unsigned int voltage)
{
    if (isStarted)
    {
        U = voltage;
        Ua = Ub = Uc = U;
        return true;
    }
    else
    {
        U = 0;
        Ua = Ub = Uc = U;
        return false;
    }
}

bool Source::increaseTargetVoltage(unsigned int voltageStep)
{
    if (isStarted)
    {
        targetU += voltageStep;
        return true;
    }
    else
    {
        return false;
    }
}

bool Source::decreaseTargetVoltage(unsigned int voltageStep)
{
    if (isStarted && ( (targetU - voltageStep) > 0 ) )
    {
        targetU -= voltageStep;
        return true;
    }
    else
    {
        return false;
    }
}

bool Source::connectToGRU()
{
    if (isStarted && U > 0)
    {
        isConnected = true;
        return true;
    }
    else
    {
        return false;
    }
}


Source::~Source(){}

bool Source::increaseTargetFrequency(unsigned int frequencyStep) {

    if (isStarted)
    {
        targetF += frequencyStep;
        return true;
    }
    else{
        return false;
    }
}

bool Source::decreaseTargetFrequency(unsigned int frequencyStep) {
    if (isStarted && ( (targetF - frequencyStep) > 0))
    {
        targetF -= frequencyStep;
        return true;
    }
    else{
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

void Source::calculateSourceU(std::chrono::milliseconds dTime) {
    U = Ua = Ub = Uc = targetU;
}

void Source::calculateSourceF(std::chrono::milliseconds dTime) {
    U = Ua = Ub = Uc = targetU;
}

double Source::computeRinternal(std::chrono::milliseconds dTime) {
    Rinternal = internalRcalculator->calculateRinternal(dTime, P, targetF, f);
    return Rinternal;
}
