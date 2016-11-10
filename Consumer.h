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
    virtual void precalculate(std::chrono::milliseconds dTime) override {}
    virtual void calculate(std::chrono::milliseconds dTime) override ;
    virtual void aftercalculation(std::chrono::milliseconds dTime) override {}

    double getPnom() const { return Pnom; }
    double getQnom() const { return Qnom; }
    double getSnom() const { return Snom; }
    virtual bool connectToGRU() override;
    virtual bool disconnectToGRU() override;

protected:
    double Pnom, Qnom, Snom;//номинальные мощности потребителя
};


#endif //LIBELECTRICITY_CONSUMER_H
