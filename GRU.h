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
#include "AllLoadDivider.h"
#include "GRU_functions.h"


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

    virtual inline double getPnomSources(){return PnomSources;}
    virtual inline double getQnomSources(){return QnomSources;}
    virtual inline double getSnomSources(){return SnomSources;}
    virtual inline double getPreserv(){return Preserv;}
    virtual inline double getQreserv(){return Qreserv;}
    virtual inline double getSreserv(){return Sreserv;}
    virtual inline double getCurrentConsumptionP(){return currentConsumptionP;}
    virtual inline double getCurrentConsumptionQ(){return currentConsumptionQ;}
    virtual inline double getCurrentConsumptionS(){return currentConsumptionS;}

protected:
    int busU={0},busF={0}; //напряжение и частота на шинах ГРУ
    double PnomSources={0}, QnomSources={0}, SnomSources={0};//номинальные мощности источников, подключенных к шинам
    double Preserv={0},Qreserv={0},Sreserv={0};//резерв мощности на шинах ГРУ
    double currentConsumptionP={0}, currentConsumptionQ={0}, currentConsumptionS={0};//текущая потребляемая с шин мощность
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
    void computeNominalSourceP();//вычисляем номинальную мощность подключенных к ГРУ источников
    void computePowerReserv();//расчитываем резервы мощностей на шинах ГРУ
};
#endif //LIBELECTRICITY_GRU_H
