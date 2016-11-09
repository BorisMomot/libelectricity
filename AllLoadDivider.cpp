//
// Created by boris on 23.10.16.
//

#include "AllLoadDivider.h"
using namespace std;

void AllLoadDivider::DivideActiveLoadBetweenSources(std::map<std::string, Source*> &sources, double PTotalLoad, std::chrono::milliseconds dTime) {
    double RintSum = computeRinSourceSum(sources, dTime);
    int AmountOFConnectedSources = computeAmountOfConnectedSources(sources);
    divideActivePowerBaseOnRinternal(sources, PTotalLoad, RintSum, AmountOFConnectedSources);
}

void AllLoadDivider::DivideReactiveLoadBetweenSources(std::map<std::string, Source *> &sources, double QTotalLoad, std::chrono::milliseconds dTime) {
    double RintSum = computeRinSourceSum(sources, dTime);
    int AmountOFConnectedSources = computeAmountOfConnectedSources(sources);
    divideReactivePowerBaseOnRinternal(sources, QTotalLoad, RintSum, AmountOFConnectedSources);
}

double AllLoadDivider::computeRinSourceSum(std::map<std::string, Source *> &sources, std::chrono::milliseconds dTime) {
    double SumRint = 0;
    auto RintSummator = [&SumRint, dTime] (Source* source) {
        if (source->getIsConnected()) {
            SumRint += source->computeRinternal(dTime);
        }
    };
    doSmthWithMapValues<Source>(sources, RintSummator);
    return SumRint;
}

int AllLoadDivider::computeAmountOfConnectedSources(std::map<std::string, Source*> &sources) {
    int amountOfConnectedSources = 0;
    auto calcAmountOfInclSources = [&amountOfConnectedSources] (Source* source) {
        if (source->getIsConnected()) {
            amountOfConnectedSources++;
        }
    };
    doSmthWithMapValues<Source>(sources, calcAmountOfInclSources);
    return amountOfConnectedSources;
}

void AllLoadDivider::divideActivePowerBaseOnRinternal(std::map<std::string, Source *> &sources, double PTotalLoad,
                                                      double RintSum, int AmountOFConnectedSources) {
    auto loadDivider = [PTotalLoad, RintSum, AmountOFConnectedSources] (Source* source) {
        if (AmountOFConnectedSources != 1) {
            source->setP( ( (RintSum - source->getRinternal()) / (RintSum*(AmountOFConnectedSources - 1)) ) * PTotalLoad );
        }
        else {
            source->setP(PTotalLoad);
        }
    };
    doSmthWithMapValues(sources, loadDivider);
}

void AllLoadDivider::divideReactivePowerBaseOnRinternal(std::map<std::string, Source *> &sources, double QTotalLoad,
                                                        double RintSum, int AmountOFConnectedSources) {
    auto loadDivider = [QTotalLoad, RintSum, AmountOFConnectedSources] (Source* source) {
        if (AmountOFConnectedSources != 1) {
            source->setQ( ( (RintSum - source->getRinternal()) / (RintSum*(AmountOFConnectedSources - 1)) ) * QTotalLoad );
        }
        else {
            source->setQ(QTotalLoad);
        }
    };
    doSmthWithMapValues(sources, loadDivider);
}


