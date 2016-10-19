//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_GRU_H
#define LIBELECTRICITY_GRU_H

#include <string>
#include <iostream>
#include <map>
#include "AbstractModel.h"
#include "Source.h"
#include "Consumer.h"

class GRU: public AbstractModel
{
public:
    GRU(){}
    virtual ~GRU(){}

    virtual void precalculate(unsigned int dTime) override;
    virtual void calculate(unsigned int dTime) override;
    virtual void aftercalculation(unsigned int dTime) override;

    virtual bool addSource(const std::string& name, Source* source);
    virtual bool addConsumer(const std::string& name, Consumer* consumer);

    virtual Source* getSourcePtr(const std::string& name);
    virtual Consumer* getConsumerPtr(const std::string& name);

    virtual inline int getCurrentU(){return busU;}
    virtual inline int getCurrentF(){return busF;}

    virtual inline int getPnomSources(){return PnomSources;}
    virtual inline int getQnomSources(){return QnomSources;}
    virtual inline int getSnomSources(){return SnomSources;}
    virtual inline int getPreserv(){return Preserv;}
    virtual inline int getQreserv(){return Qreserv;}
    virtual inline int getSreserv(){return Sreserv;}
    virtual inline int getCurrentConsumptionP(){return currentConsumptionP;}
    virtual inline int getCurrentConsumptionQ(){return currentConsumptionQ;}
    virtual inline int getCurrentConsumptionS(){return currentConsumptionS;}
private:
    int busU,busF; //напряжение и частота на шинах ГРУ
    int PnomSources, QnomSources, SnomSources;//номинальные мощности источников, подключенных к шинам
    int Preserv,Qreserv,Sreserv;//резерв мощности на шинах ГРУ
    int currentConsumptionP, currentConsumptionQ, currentConsumptionS;//текущая потребляемая с шин мощность
    std::map<std::string, Source*> sources;
    std::map<std::string, Consumer*> consumers;

    void computeCurrentPconsumptions();//вычисляем текущую потребляемую мощность для всех потребителей и источников
    void computeNominalSourceP();//вычисляем номинальную мощность подключенных к ГРУ источников
    void computeBusVoltage();//вычисляем напряжение на шинах
    void computeBusFrequency();//вычисляем частоту на шинах ГРУ
    void setBusVoltageToAll();//выстявляем общее напряжение для всего, что подключено к ГРУ
    void setBusFrequencyToAll();//выстявляем общую частоту для всего, что подключено к ГРУ
};


#endif //LIBELECTRICITY_GRU_H
