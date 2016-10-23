//
// Created by boris on 23.10.16.
//

#include "ActiveLoadDivider.h"
using namespace std;

void ActiveLoadDivider::DivideActiveLoadBetweenSources(std::map<std::string, Source*> &sources, double PTotalLoad) {
    double RintSum = computeRinSourceSum(sources);
    double AmountOFConnectedSources = computeAmountOfConnectedSources(sources);
    divideBaseOnRinternal(sources, PTotalLoad, RintSum, AmountOFConnectedSources);
}

//double ActiveLoadDivider::computePnom(std::map<std::string, Source*> &sources) {
//    double PnomSources = 0;
//    for (map<string, Source*>::iterator it=sources.begin(); it!=sources.end(); ++it) {
//        if (it->second->getIsConnected()) {
//            PnomSources += it->second->getPnominal();
//        }
//    }
//    return PnomSources;
//}

double ActiveLoadDivider::computeRinSourceSum(std::map<std::string, Source *> &sources) {
    double SumRint = 0;
    auto RintSummator = [&SumRint] (Source* source) {
        if (source->getIsConnected()) {
            SumRint += source->getRinternal();
        }
    };
    doSmthWithMapValues<Source>(sources, RintSummator);
    return SumRint;
}

int ActiveLoadDivider::computeAmountOfConnectedSources(std::map<std::string, Source*> &sources) {
    int amountOfConnectedSources = 0;
    auto calcAmountOfInclSources = [&amountOfConnectedSources] (Source* source) {
        if (source->getIsConnected()) {
            amountOfConnectedSources++;
        }
    };
    doSmthWithMapValues<Source>(sources, calcAmountOfInclSources);
    return amountOfConnectedSources;
}

void ActiveLoadDivider::divideBaseOnRinternal(std::map<std::string, Source*> &sources, double PTotalLoad, double RintSum, int AmountOFConnectedSources) {
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
