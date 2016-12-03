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
    bool isConnectedCached = isConnected;
    double Ucached = U;
    if (isConnectedCached && (Ucached > 0))
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
    bool isConnectedCached = isConnected;
    double Ucached = U;
    if (isConnectedCached && (Ucached > 0))
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
    bool isConnectedCached = isConnected;
    double Ucached = U;
    if (isConnectedCached && (Ucached > 0))
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
    double Pcached = P;
    double Qcached = Q;
    double Pphase = Pcached/3;
    double Qphase = Qcached/3;
    Pa=Pb=Pc=Pphase;
    Qa=Qb=Qc=Qphase;
    double Scached = sqrt(Pcached*Pcached + Qcached*Qcached);
    S = Scached;
    double Sphase = Scached/3;
    Sa=Sb=Sc=Sphase;
}

void AbstractElModel::calculateCurrents()
{
    double Ucached = U;
    double Scached = S;
    double Icached;
    if (Ucached>0)
    {
        Icached = Scached / Ucached;
    }
    else
    {
        Icached = 0;
    }
    I = Icached;
    Ia=Ib=Ic=Icached/3;
}

AbstractElModel::~AbstractElModel(){}

void AbstractElModel::resetParametersToZero() {
    P = Q = S = Pa = Pb = Pc = Qa = Qb = Qc = Sa = Sb = Sc = I = Ia = Ib = Ic = 0;
}
