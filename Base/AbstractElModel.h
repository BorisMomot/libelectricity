//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_ABSTRACTELMODEL_H
#define LIBELECTRICITY_ABSTRACTELMODEL_H
/**
 * \brief Класс абстрактной электрической модели, содержит много электрических параметров
 * Задумывался как интерфейс для большинства электрических моделей
 * В классе расчитывается большое количество электрических параметров, верных для большинства электрических моделей
 * Расчитываются фазные токи, линейные напряжения, фазные мощности по примитивным формулам.
 */

#include "AbstractModel.h"
#include <atomic>

class AbstractElModel: public AbstractModel
{
public:
    AbstractElModel();
    /**
     * Установить для модели текущую активную мощность
     * @param power - задаваемая активная мощность
     * @return - если в текущем состоянии можно задать мощность для модели, в противном случае выставление мощности будет проигнорировано
     */
    virtual inline bool setP(double power);
    /**
     * Установить для модели текущую реактивную мощность
     * @param reactpower - задаваемая реактивная мощность
     * @return - если в текущем состоянии можно задать мощность для модели, в противном случае выставление мощности будет проигнорировано
     */
    virtual inline bool setQ(double reactpower);
    /**
     * Установить для модели частоту наряжения
     * @param frequency - задаваемая частота
     * @return - если в текущем состоянии можно задать частоту для модели, в противном случае выставление частоты будет проигнорировано
     */
    virtual inline bool setF(unsigned int frequency);
    /**
     * Установить для модели наряжение
     * @param voltage - задаваемое напряжение
     * @return - если в текущем состоянии можно задать напряжение для модели, в противном случае выставление напряжения будет проигнорировано
     */
    virtual inline bool setU(unsigned int voltage);

    virtual inline bool connectToGRU(){isConnected = true; return true;}
    virtual inline bool disconnectToGRU(){isConnected = false; return true;}
    inline bool getIsConnected(){return isConnected;}

    virtual inline double getP(){return P;}
    virtual inline double getQ(){return Q;}
    virtual inline double getS(){return S;}
    virtual inline double getPa(){return Pa;}
    virtual inline double getPb(){return Pb;}
    virtual inline double getPc(){return Pc;}
    virtual inline double getQa(){return Qa;}
    virtual inline double getQb(){return Qb;}
    virtual inline double getQc(){return Qc;}
    virtual inline double getSa(){return Sa;}
    virtual inline double getSb(){return Sb;}
    virtual inline double getSc(){return Sc;}
    virtual inline double getf(){return f;}
    virtual inline double getI(){return I;}
    virtual inline double getU(){return U;}
    virtual inline double getIa(){return Ia;}
    virtual inline double getIb(){return Ib;}
    virtual inline double getIc(){return Ic;}
    virtual inline double getUa(){return Ua;}
    virtual inline double getUb(){return Ub;}
    virtual inline double getUc(){return Uc;}
    double getUbus() const { return Ubus; }
    double getFbus() const { return Fbus; }
    virtual void setUbus(double Ubus) { AbstractElModel::Ubus = Ubus; }
    virtual void setFbus(double Fbus) { AbstractElModel::Fbus = Fbus; }

    /**
     * Расчитывает на основании P, Q, полную мощность S и мощности по фазам
     */
    virtual void calculatePowers();
    /**
     * Расчитывает на основании I токи по фазам
     */
    virtual void calculateCurrents();

    virtual void precalculate(std::chrono::milliseconds dTime) override {}
    /**
     * Расчитывает calculatePowers и calculateCurrents
     * @param dTime
     */
    virtual void calculate(std::chrono::milliseconds dTime) override; //todo подумать насчет вынесения интерфейса и дефолтной логике автомата в этот класс
    virtual void aftercalculation(std::chrono::milliseconds dTime) override {}

    virtual ~AbstractElModel() = 0;
protected:
    virtual void resetParametersToZero();
    std::atomic<double> P={0},Q={0},S={0};
    std::atomic<double> Pa={0},Pb={0},Pc={0},Qa={0},Qb={0},Qc={0},Sa={0},Sb={0},Sc={0};
    std::atomic<double> f={0},I={0},U={0};
    std::atomic<double> Ia={0},Ib={0},Ic={0},Ua={0},Ub={0},Uc={0};
    /**
     * подключен ли потребитель к шинам ГРУ
     */
    bool isConnected={false};
    /**
     * напряжение и частота на шинах ГРУ к которым предполагается подключать данную модель
     */
    double Ubus={0}, Fbus={0};//напряжение и частота на шинах
};


#endif //LIBELECTRICITY_ABSTRACTELMODEL_H
