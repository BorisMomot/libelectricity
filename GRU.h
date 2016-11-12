//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_GRU_H
#define LIBELECTRICITY_GRU_H
/**
 * \brief Модель ГРУ
 * Модель ГРУ хранит ссылки на подключаемые к ней источники и потребители. В задачи ГРУ входит расчет напряжения и
 * частоты на шинах, расчет суммарного потребления, резерва мощности, распределение нагрузки между источниками энергии,
 * а так же вызов фукнций расчета для всех моделей на которые ГРУ хранит ссылки
 */
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

    virtual void precalculate(std::chrono::milliseconds dTime) override;
    virtual void calculate(std::chrono::milliseconds dTime) override;
    virtual void aftercalculation(std::chrono::milliseconds dTime) override;
    /**
     * Добавить к ГРУ источник
     * @param name - название источника (должно быть уникальным)
     * @param source - ссылка на модель источника (может дублироваться)
     * @return - true в случае успешного добавления
     */
    virtual bool addSource(const std::string& name, Source* source);
    /**
     * Добавить к ГРУ потребителя
     * @param name - названия потребителя (должно быть уникальным)
     * @param consumer - ссылка на модель потребителя (может дублироваться)
     * @return - true в случае успешного добавления
     */
    virtual bool addConsumer(const std::string& name, Consumer* consumer);
    /**
     * ищет ссылку на источник name, если находит - возвращает ее, если нет, то возвращает пустой указатель
     * @param name - имя источника
     * @return - ссылка на найденный источник
     */
    virtual Source* getSourcePtr(const std::string& name);
    /**
     * ищет ссылку на модель потребителя name, если находит - возвращает ее, если нет, то возвращает пустой указатель
     * @param name - имя потребителя
     * @return - ссылка на найденную модель потребителя
     */
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
    virtual inline double getSumRint() const {return SumRint;}
protected:
    /**
     * Напряжение и частота на шинах ГРУ
     */
    int busU={0},busF={0};
    /**
     * Сумма номинальных мощностей источников подключенных к шинам ГРУ
     */
    double PnomSources={0}, QnomSources={0}, SnomSources={0};
    /**
     * Суммарный резерв мощности для всех источников подключенных к ГРУ
     */
    double Preserv={0},Qreserv={0},Sreserv={0};
    /**
     * Текущая суммарная мощность, потребляемая всеми потребителями
     */
    double currentConsumptionP={0}, currentConsumptionQ={0}, currentConsumptionS={0};//текущая потребляемая с шин мощность
    /**
     * Суммарное внутреннее сопротивление всех источников подключенных к шинам
     */
    double SumRint={0};


protected:
    //суммарное внутреннее сопротивление всех источников на шинах
    int amountOfConnectedSources={0}; //количество источников подключенных к шинам ГРУ
    std::map<std::string, Source*> sources;
    std::map<std::string, Consumer*> consumers;

    void computeSourcesUandF(std::chrono::milliseconds dTime);//вычисляет напряжение и частоту на источниках, до выравнивания в ГРУ
    void computeBusVoltage();//вычисляем напряжение на шинах
    void setBusVoltageToAll();//выстявляем общее напряжение для всего, что подключено к ГРУ
    void computeBusFrequency();//вычисляем частоту на шинах ГРУ
    void setBusFrequencyToAll();//выстявляем общую частоту для всего, что подключено к ГРУ
    void computeCurrentGRUPconsumptions();//вычисляем текущую потребляемую мощность на ГРУ
    void devideConsumptedPowerBetweenGenerators(std::chrono::milliseconds dTime);//вычисляем мощность производимую всеми источниками
    void computeSumRint(std::chrono::milliseconds dTime);//вычисляем суммарное сопротивление источников подключенных к ГРУ
    void computeNominalSourceP();//вычисляем номинальную мощность подключенных к ГРУ источников
    void computePowerReserv();//расчитываем резервы мощностей на шинах ГРУ
};
#endif //LIBELECTRICITY_GRU_H
