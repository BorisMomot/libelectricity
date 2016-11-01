//
// Created by boris on 01.11.16.
//

#ifndef LIBELECTRICITY_SIMPLEDRIVE_H
#define LIBELECTRICITY_SIMPLEDRIVE_H

#include "Consumer.h"

class SimpleDrive: public Consumer {
public:
    SimpleDrive(unsigned int Pnominal, unsigned int RPMnom, unsigned int Qnominal  = 0);

    virtual void calculate(unsigned int dTime) override;
    bool setRPM(int targetRPM);

    inline int getTargetRPM() const { return targetRPM; }
    inline int getRPM() const { return RPM; }
    inline double getK() const { return k; }

protected:
    void computeDrivePowers();
    int targetRPM = {0};
    int RPM = {0};
    double k = {0}; //Наклон нагрузочной характеристики привода
};


#endif //LIBELECTRICITY_SIMPLEDRIVE_H
