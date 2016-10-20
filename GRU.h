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
#include "LoadDivider.h"

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

protected:
    int busU,busF; //напряжение и частота на шинах ГРУ
    int PnomSources, QnomSources, SnomSources;//номинальные мощности источников, подключенных к шинам
    int Preserv,Qreserv,Sreserv;//резерв мощности на шинах ГРУ
    int currentConsumptionP, currentConsumptionQ, currentConsumptionS;//текущая потребляемая с шин мощность
    double SumRint={0}; //суммарное внутреннее сопротивление всех источников на шинах
    int amountOfConnectedSources={0}; //количество источников подключенных к шинам ГРУ
    std::map<std::string, Source*> sources;
    std::map<std::string, Consumer*> consumers;

    void computeSourcesUandF(unsigned int dTime);//вычисляет напряжение и частоту на источниках, до выравнивания в ГРУ
    void computeBusVoltage();//вычисляем напряжение на шинах
    void setBusVoltageToAll();//выстявляем общее напряжение для всего, что подключено к ГРУ
    void computeBusFrequency();//вычисляем частоту на шинах ГРУ
    void setBusFrequencyToAll();//выстявляем общую частоту для всего, что подключено к ГРУ
    void computeCurrentPconsumptions();//вычисляем текущую потребляемую мощность для всех и источников
    void computeCurrentPgeneration();//вычисляем мощность производимую всеми источниками
    int computeAmountOfConnetctedSources();
    double computeSumRInternal();
    void computeNominalSourceP();//вычисляем номинальную мощность подключенных к ГРУ источников
    void DivideLoadBetweenSources();//делим нагрузку между источниками

    template <typename MapType, typename Functor>
    void doSmthWithMapValues(std::map<std::string, MapType *> _map, Functor function){
        for (auto&& Item : _map) {
            function(Item.second);
        }
    }
};
#endif //LIBELECTRICITY_GRU_H
