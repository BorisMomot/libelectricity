//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_SOURCE_H
#define LIBELECTRICITY_SOURCE_H
/**
 * \brief Максимально простой источник электрической энергии. А так же интерфейс для более сложных источников
 * За один расчет отрабатывает задание по частоте и уровню напряжения
 */
#include "AbstractElModel.h"
#include "RintCalculator.h"

class Source: public AbstractElModel
{
public:
    Source(double Pnominal, double Qnominal, double Unominal = 400);
    virtual ~Source();

    virtual void precalculate(std::chrono::milliseconds dTime) override {}
    virtual void calculate(std::chrono::milliseconds dTime) override ;
    virtual void aftercalculation(std::chrono::milliseconds dTime) override {}

    virtual inline bool startSource(){isStarted = true; return true;}
    virtual inline bool getIsStarted(){return isStarted;}
    virtual bool stopSource();

    virtual void computeSourceU(std::chrono::milliseconds dTime);
    virtual void computeSourceF(std::chrono::milliseconds dTime);

    /**
     * Вызывается ГРУ для выставления единой частоты на шинах для всех источников
     * @param frequency - частота
     * @return - true если удачно
     */
	virtual bool setF(unsigned int frequency) override;
	/**
	 * Вызывается ГРУ для выставления единого напряжения на шинах для всех источников
	 * @param voltage - напряжение
	 * @return - true если удачно
	 */
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
    virtual inline double computeRinternal(std::chrono::milliseconds dTime);
    virtual inline double getRinternal(){return Rinternal;}

    bool setRCalculator(RintCalculator* Rcalc);
protected:
	/**
	 * номинальные мощности источника
	 */
	std::atomic<double> Pnom={0}, Qnom={0}, Snom={0};
	/**
	 * номинальное напряжение источника
	 */
	std::atomic<double> Unom={0};
	/**
	 * заданные системе управления источником эл. энергии задания по частоте и напряжению
	 */
	std::atomic<double> targetU={0}, targetF={50};
	/**
	 * внутреннее сопротивление источника
	 */
	std::atomic<double> Rinternal={0};
	/**
	 * признак, что текущая мощность больше номинальной мощности источника
	 */
	std::atomic<bool> isOverLoaded = {false};
	/**
	 * признак, что источник запущен
	 */
	std::atomic<bool> isStarted={false};
	/**
	 * ссылка на объект, который будет рассчитывать внутреннее сопротивление источника
	 */
    RintCalculator *internalRcalculator;
};


#endif //LIBELECTRICITY_SOURCE_H
