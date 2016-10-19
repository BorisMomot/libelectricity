//
// Created by boris on 19.10.16.
//

#ifndef LIBELECTRICITY_LOADDIVIDER_H
#define LIBELECTRICITY_LOADDIVIDER_H


class LoadDivider {
public:
    static double calculateSourceLoad(double PtotalLoad, double Rtotatl, double Rsource, double amountOfSources);
};


#endif //LIBELECTRICITY_LOADDIVIDER_H
