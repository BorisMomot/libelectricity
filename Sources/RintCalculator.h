//
// Created by boris on 19.10.16.
//

#ifndef LIBELECTRICITY_RINTCALCULATOR_H
#define LIBELECTRICITY_RINTCALCULATOR_H
/**
 * \brief Класс для расчета внутреннего сопротивления источника
 * На основе номинальной мощности, напряжения, КПД, конструктивного коэффициента машины, критического момента машины,
 * текущей мощности, текущей частоты и уставке по частоте высчитывается внутреннее сопротивление источника
 * Вычисление внутреннего сопротивления происходит по формулам:
 */
//todo написать формулу
#include <chrono>

class RintCalculator {
public:
	/**
	 * Конструктор
	 * @param Pnominal - номинальная мощность источника
	 * @param Unominal - номинальное напряжение источника
	 * @param EfficiencyNominal - КПД номинальный
	 * @param Kkonstractional - конструктивный коэффициент машины
	 * @return
	 */
    RintCalculator(unsigned int Pnominal, unsigned int Unominal, double EfficiencyNominal=0.98, unsigned int Kkonstractional=1);
	/**
	 * расчитать текущее внутреннее сопротивление источника
	 * @param dTime - время с момента последнего вызова функции
	 * @param Pcurrent - текущая мощность
	 * @param Ftarget - уставка по частоте вращения
	 * @param Fcurrent - текущая частота вращения
	 * @param Pkr - критическая мощность генератора (после которой вываливание из синхронизма)
	 * @return - внутреннее сопротивление
	 */
    virtual double computeRinternal(std::chrono::milliseconds dTime, double Pcurrent, double Ftarget, double Fcurrent,
                                    double Pkr = 0);
    /**
     * расчитать угол нагрузки для источника (угла между магнитным полем ротора и статора)
     * @param dTime - время с момента последнего вызова функции
     * @param Pcurrent - текущая мощность
     * @param Ftarget - уставка по частоте вращения
     * @param Fcurrent - текущая частота вращения
     * @param Pkr - критическая мощность генератора (после которой вываливание из синхронизма)
     * @return угол нагрузки
     */
	virtual double computeSinFi(std::chrono::milliseconds dTime, double Pcurrent, double Ftarget, double Fcurrent,
	                            double Pkr = 0);
protected:
    unsigned int Pnom, Unom, Kkonstr;
    double EfficiencyNom;
};

#endif //LIBELECTRICITY_RINTCALCULATOR_H
