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
#include "Convinience_functions.h"


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
    std::atomic<int> busU={0},busF={0};
    /**
     * Сумма номинальных мощностей источников подключенных к шинам ГРУ
     */
    std::atomic<double> PnomSources={0}, QnomSources={0}, SnomSources={0};
    /**
     * Суммарный резерв мощности для всех источников подключенных к ГРУ
     */
    std::atomic<double> Preserv={0},Qreserv={0},Sreserv={0};
    /**
     * Текущая суммарная мощность, потребляемая всеми потребителями
     */
    std::atomic<double> currentConsumptionP={0}, currentConsumptionQ={0}, currentConsumptionS={0};//текущая потребляемая с шин мощность
    /**
     * Суммарное внутреннее сопротивление всех источников подключенных к шинам
     */
    std::atomic<double> SumRint={0};

    /**
     * количество подключенных к шинам ГРУ источников электрических энергии
     */
    std::atomic<int> amountOfConnectedSources={0};
    /**
     * Мапы источников, которые могут быть подключены к ГРУ
     */
    std::map<std::string, Source*> sources;
    /**
     * Мапы потребителей, которые могут быть подключены к ГРУ
     */
    std::map<std::string, Consumer*> consumers;
    /**
     * вычисляет напряжение и частоту на источниках, до выравнивания в ГРУ
     * @param dTime - время с момента последнего вызова функции
     */
    void computeSourcesUandF(std::chrono::milliseconds dTime);
    /**
     * вычислить напряжение на шинах ГРУ
     */
    void computeBusVoltage();
    /**
     * выставить напряжение ГРУ для всех источников и потребителей подключенных к шинам
     */
    void setBusVoltageToAll();
    /**
     * вычислить частоту на шинах ГРУ
     */
    void computeBusFrequency();
    /**
     * выставить частоту ГРУ для всех источников и потребителей подключенных к шинам
     */
    void setBusFrequencyToAll();
    /**
     * вычисляем суммарную потребляемую мощность с шин ГРУ
     */
    void computeCurrentGRUPconsumptions();
    /**
     * вычисленную потребляемую мощность делим между источниками
     * @param dTime - время с момента последнего вызова функции
     */
    void devideConsumptedPowerBetweenGenerators(std::chrono::milliseconds dTime);
    /**
     * вычисляем суммарное сопротивление источников подключенных к ГРУ
     * @param dTime - время с момента последнего вызова функции
     */
    void computeSumRint(std::chrono::milliseconds dTime);
    /**
     * вычисляем суммарную номинальную мощность для всех источников подключенных к шинам ГРУ
     */
    void computeNominalSourceP();
    /**
     * вычисляем резерв мощности на шинах ГРУ
     */
    void computePowerReserv();//
};
#endif //LIBELECTRICITY_GRU_H
