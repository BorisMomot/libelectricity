//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_SOURCE_H
#define LIBELECTRICITY_SOURCE_H


#include "AbstractElModel.h"
#include "RintCalculator.h"

class Source: public AbstractElModel
{
public:
    Source(unsigned int Pnominal, unsigned int Qnominal, unsigned int Unominal=400);
    virtual ~Source();

    virtual void precalculate(unsigned int dTime) override {}
    virtual void calculate(unsigned int dTime) override ;
    virtual void aftercalculation(unsigned int dTime) override {}

    virtual inline bool startSource(){isStarted = true; return true;}
    virtual inline bool getIsStarted(){return isStarted;}
    virtual bool stopSource();

    virtual bool setF(unsigned int frequency) override;
    virtual bool setU(unsigned int voltage) override;
    virtual inline bool setTargetU(unsigned int Utarget){targetU = Utarget; return true;}
    virtual inline bool setTargetF(unsigned int Ftarget){targetF = Ftarget; return true;}
    virtual bool increaseTargetVoltage(unsigned int voltageStep = 1);
    virtual bool decreaseTargetVoltage(unsigned int voltageStep = 1);
    virtual bool increaseTargetFrequency(unsigned int frequencyStep = 1);
    virtual bool decreaseTargetFrequency(unsigned int frequencyStep = 1);
    virtual bool connectToGRU() override;

    virtual inline double getPnominal(){return Pnom;}
    virtual inline double getQnominal(){return Qnom;}
    virtual inline double getSnominal(){return Snom;}
    virtual inline double getUnominal(){return Unom;}
    virtual inline double getTargetF(){return targetF;}
    virtual inline double getTargetU(){return targetU;}
    virtual inline double getRinternal(){return Rinternal;}

    bool setRCalculator(RintCalculator* Rcalc);
protected:
    double Pnom, Qnom, Snom; //номинальные мощности источника
    double Unom; //номинальное напряжение источника
    double targetU, targetF={50}; //заданные системе управления источником эл. энергии задания по частоте и напряжению
    double Rinternal; //внутреннее сопротивление источника
    bool isOverLoaded = {false};
    bool isStarted;
    RintCalculator *internalRcalculator;//ссылка на объект, который будет рассчитывать внутреннее сопротивление источника


};


#endif //LIBELECTRICITY_SOURCE_H
