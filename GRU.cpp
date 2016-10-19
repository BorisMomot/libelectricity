//
// Created by boris on 18.10.16.
//

#include "GRU.h"

using namespace std;

void GRU::precalculate(unsigned int dTime)
{
    for (map<string, Consumer*>::iterator it=consumers.begin(); it!=consumers.end(); ++it)
    {
        it->second->precalculate(dTime);
    }
    for (map<string, Source*>::iterator it=sources.begin(); it!=sources.end(); ++it)
    {
        it->second->precalculate(dTime);
    }
}
void GRU::aftercalculation(unsigned int dTime)
{
    for (map<string, Consumer*>::iterator it=consumers.begin(); it!=consumers.end(); ++it)
    {
        it->second->aftercalculation(dTime);
    }
    for (map<string, Source*>::iterator it=sources.begin(); it!=sources.end(); ++it)
    {
        it->second->aftercalculation(dTime);
    }
}
void GRU::calculate(unsigned int dTime)
{
    computeBusVoltage();
    computeBusFrequency();
    setBusVoltageToAll();
    setBusFrequencyToAll();

    for (map<string, Consumer*>::iterator it=consumers.begin(); it!=consumers.end(); ++it)
    {
        it->second->calculate(dTime);
    }

    computeCurrentPconsumptions();

    for (map<string, Source*>::iterator it=sources.begin(); it!=sources.end(); ++it)
    {
        it->second->calculate(dTime);
    }
}

void GRU::computeBusVoltage()
{
    unsigned int AmountOfSources = 0;
    double Utemp;
    for (map<string, Source*>::iterator it=sources.begin(); it!=sources.end(); ++it)
    {
        if (it->second->getIsConnected())
        {
            Utemp += it->second->getU();
            AmountOfSources++;
        }
    }
    if (AmountOfSources > 0)
    {
        busU = Utemp/AmountOfSources;
    }
    else
    {
        busU = 0;
    }
}

void GRU::computeBusFrequency()
{
    unsigned int AmountOfSources = 0;
    double Ftemp;
    for (map<string, Source*>::iterator it=sources.begin(); it!=sources.end(); ++it)
    {
        if (it->second->getIsConnected())
        {
            Ftemp += it->second->getf();
            AmountOfSources++;
        }
    }
    if (AmountOfSources > 0)
    {
        busF = Ftemp/AmountOfSources;
    }
    else
    {
        busF = 0;
    }
}

void GRU::setBusVoltageToAll()
{
    for (map<string, Consumer*>::iterator it=consumers.begin(); it!=consumers.end(); ++it)
    {
        if (it->second->getIsConnected())
        {
            it->second->setU(busU);
        }
    }
    for (map<string, Source*>::iterator it=sources.begin(); it!=sources.end(); ++it)
    {
        if (it->second->getIsConnected())
        {
            it->second->setU(busU);
        }
    }
}

void GRU::setBusFrequencyToAll()
{
    for (map<string, Consumer*>::iterator it=consumers.begin(); it!=consumers.end(); ++it)
    {
        if (it->second->getIsConnected())
        {
            it->second->setF(busF);
        }
    }
    for (map<string, Source*>::iterator it=sources.begin(); it!=sources.end(); ++it)
    {
        if (it->second->getIsConnected())
        {
            it->second->setF(busF);
        }
    }
}
void GRU::computeCurrentPconsumptions()
{
    currentConsumptionP=0;
    currentConsumptionQ=0;
    currentConsumptionS=0;
    //вычисляем общую потребляемую мощность
    for (map<string, Consumer*>::iterator it=consumers.begin(); it!=consumers.end(); ++it)
    {
        if (it->second->getIsConnected())
        {
            currentConsumptionP += it->second->getP();
            currentConsumptionQ += it->second->getQ();
            currentConsumptionS += it->second->getS();
        }
    }
    computeNominalSourceP();
    //делим ее между источниками
    for (map<string, Source*>::iterator it=sources.begin(); it!=sources.end(); ++it)
    {
        if (it->second->getIsConnected())
        {
            it->second->setP((it->second->getPnominal()/PnomSources) * currentConsumptionP);
            it->second->setQ((it->second->getQnominal()/QnomSources) * currentConsumptionQ);
        }
    }
}
void GRU::computeNominalSourceP()
{
    PnomSources = 0;
    QnomSources = 0;
    SnomSources = 0;
    for (map<string, Source*>::iterator it=sources.begin(); it!=sources.end(); ++it)
    {
        if (it->second->getIsConnected())
        {
            PnomSources += it->second->getPnominal();
            QnomSources += it->second->getQnominal();
            SnomSources += it->second->getSnominal();
        }
    }
}


bool GRU::addConsumer(const string &name, Consumer* consumer)
{
    consumers.insert(pair<string, Consumer*> (name, consumer) );
    return true;
}

bool GRU::addSource(const string &name, Source* source)
{
    sources.insert(pair<string, Source*> (name, source) );
    return true;
}

Source* GRU::getSourcePtr(const string &name)
{
    return (sources.find(name)->second);
}

Consumer* GRU::getConsumerPtr(const string &name)
{
    return (consumers.find(name)->second);
}
