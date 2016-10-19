//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_CONSUMER_H
#define LIBELECTRICITY_CONSUMER_H

#include "AbstractElModel.h"

class Consumer: public AbstractElModel
{
public:
    Consumer(unsigned int Pnominal, unsigned int Qnominal = 0);
    virtual ~Consumer(){}
    virtual void precalculate(unsigned int dTime) override {}
    virtual void calculate(unsigned int dTime) override ;
    virtual void aftercalculation(unsigned int dTime) override {}
protected:
    double Pnom, Qnom, Snom; //номинальные мощности потребителя
};


#endif //LIBELECTRICITY_CONSUMER_H
