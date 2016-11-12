//
// Created by boris on 18.10.16.
//

#include "AbstractElModel.h"
#include <math.h>

AbstractElModel::AbstractElModel()
{
}

bool AbstractElModel::setF(unsigned int frequency)
{
    if (isConnected && (U > 0))
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

bool AbstractElModel::setP(double power)
{
    if (isConnected && (U > 0))
    {
        P = power;
        return true;
    }
    else
    {
        P = 0;
        return false;
    }
}

bool AbstractElModel::setQ(double reactpower)
{
    if (isConnected && (U > 0))
    {
        Q = reactpower;
        return true;
    }
    else
    {
        Q = 0;
        return false;
    }
}


bool AbstractElModel::setU(unsigned int voltage)
{
    if (isConnected)
    {
        U = Ua = Ub = Uc = voltage;
        return true;
    }
    else
    {
        U = 0;
        return false;
    }
}

void AbstractElModel::calculate(std::chrono::milliseconds dTime)
{
    calculatePowers();
    calculateCurrents();
}

void AbstractElModel::calculatePowers()
{
    Pa=Pb=Pc=P/3;
    Qa=Qb=Qc=Q/3;
    S=sqrt(P*P + Q*Q);
    Sa=Sb=Sc=S/3;
}

void AbstractElModel::calculateCurrents()
{
    if (U>0)
    {
        I=P/U;
    }
    else
    {
        I=0;
    }
    Ia=Ib=Ic=I/3;
}

AbstractElModel::~AbstractElModel(){}

void AbstractElModel::resetParametersToZero() {
    P = Q = S = Pa = Pb = Pc = Qa = Qb = Qc = Sa = Sb = Sc = I = Ia = Ib = Ic = 0;
}
