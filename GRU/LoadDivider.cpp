//
// Created by boris on 19.10.16.
//

#include "LoadDivider.h"

double LoadDivider::calculateSourceLoad(double PtotalLoad, double Rtotatl, double Rsource, double amountOfSources) {
    if (amountOfSources != 1) {
        return ( (Rtotatl - Rsource) / (Rtotatl*(amountOfSources - 1)) ) * PtotalLoad;
    }
    else {
        return PtotalLoad;
    }
}
