//
// Created by boris on 18.10.16.
//

#include "GRU.h"

using namespace std;

void GRU::precalculate(unsigned int dTime)
{
    auto precalc = [dTime] (AbstractElModel* model){ model->precalculate(dTime); };
    doSmthWithMapValues<Consumer>(consumers, precalc);
    doSmthWithMapValues<Source>(sources, precalc);
}
void GRU::aftercalculation(unsigned int dTime)
{
    auto aftercalc = [dTime] (AbstractElModel* model){ model->aftercalculation(dTime); };
    doSmthWithMapValues<Consumer>(consumers, aftercalc);
    doSmthWithMapValues<Source>(sources, aftercalc);
}
void GRU::calculate(unsigned int dTime)
{
    computeBusVoltage();
    computeBusFrequency();
    setBusVoltageToAll();
    setBusFrequencyToAll();
    computeCurrentPconsumptions();
    auto calc = [dTime] (AbstractElModel* model){ model->calculate(dTime); };
    doSmthWithMapValues<Consumer>(consumers, calc);
    computeCurrentPgeneration();
    doSmthWithMapValues<Source>(sources, calc);
}

void GRU::computeBusVoltage()
{
    unsigned int AmountOfSources = 0;
    double Utemp = 0;

    auto busUcalc = [&Utemp, &AmountOfSources] (Source* source) {
        if (source->getIsConnected()) {
            Utemp += source->getU();
            AmountOfSources++;
        }
    };
    doSmthWithMapValues<Source>(sources, busUcalc);
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
    double Ftemp = 0;
    auto busFcalc = [&Ftemp, &AmountOfSources] (Source* source) {
        if (source->getIsConnected()) {
            Ftemp += source->getf();
            AmountOfSources++;
        }
    };
    doSmthWithMapValues<Source>(sources, busFcalc);
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
    auto busUcopy = busU;
    auto USetter = [busUcopy] (AbstractElModel* model) {
        if (model->getIsConnected()){
            model->setU(busUcopy);
        }
    };
    doSmthWithMapValues<Consumer>(consumers, USetter);
    doSmthWithMapValues<Source>(sources, USetter);
}

void GRU::setBusFrequencyToAll()
{
    auto busFCopy = busF;
    auto FSetter = [busFCopy] (AbstractElModel* model) {
        if (model->getIsConnected()){
            model->setF(busFCopy);
        }
    };
    doSmthWithMapValues<Consumer>(consumers, FSetter);
    doSmthWithMapValues<Source>(sources, FSetter);
}
void GRU::computeCurrentPconsumptions()
{
    currentConsumptionP=0;
    currentConsumptionQ=0;
    currentConsumptionS=0;
    //вычисляем общую потребляемую мощность
    auto& currentConsumptionPCopy = currentConsumptionP;
    auto& currentConsumptionQCopy = currentConsumptionQ;
    auto& currentConsumptionSCopy = currentConsumptionS;
    auto consumptionComputer = [&currentConsumptionPCopy, &currentConsumptionQCopy, &currentConsumptionSCopy] (Consumer* consumer) {
        if (consumer->getIsConnected()) {
            currentConsumptionPCopy += consumer->getP();
            currentConsumptionQCopy += consumer->getQ();
            currentConsumptionSCopy += consumer->getS();
        }
    };
    doSmthWithMapValues<Consumer>(consumers, consumptionComputer);
}

void GRU::DivideLoadBetweenSources() {
    auto& currentConsumptionPCopy = currentConsumptionP;
    auto& SumRintCopy = SumRint;
    auto& amountOfConnectedSourcesCopy = amountOfConnectedSources;
    auto& currentConsumptionQCopy = currentConsumptionQ;

    auto loadDivider = [&currentConsumptionPCopy, &SumRintCopy, &amountOfConnectedSourcesCopy, &currentConsumptionQCopy] (Source* source) {
        source->setP(LoadDivider::calculateSourceLoad(currentConsumptionPCopy, SumRintCopy, source->getRinternal(),
                                                      amountOfConnectedSourcesCopy) );
        source->setQ(LoadDivider::calculateSourceLoad(currentConsumptionPCopy, SumRintCopy, source->getRinternal(),
                                                      amountOfConnectedSourcesCopy) / currentConsumptionPCopy *
                     currentConsumptionQCopy);
    };
    doSmthWithMapValues(sources, loadDivider);
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

void GRU::computeCurrentPgeneration() {
    computeNominalSourceP();
    computeSumRInternal();
    computeAmountOfConnetctedSources();
    DivideLoadBetweenSources();
}

int GRU::computeAmountOfConnetctedSources() {
    amountOfConnectedSources = 0;
    auto& amountOfConnectedSourcesCopy = amountOfConnectedSources;
    auto calcAmountOfInclSources = [&amountOfConnectedSourcesCopy] (Source* source) {
        if (source->getIsConnected()) {
            amountOfConnectedSourcesCopy++;
        }
    };
    doSmthWithMapValues<Source>(sources, calcAmountOfInclSources);
    return amountOfConnectedSources;
}

double GRU::computeSumRInternal() {
    SumRint = 0;
    auto& SumRintCopy = SumRint;
    auto RintSummator = [&SumRintCopy] (Source* source) {
        if (source->getIsConnected()) {
            SumRintCopy += source->getRinternal();
        }
    };
    doSmthWithMapValues<Source>(sources, RintSummator);
    return SumRint;
}
