//
// Created by boris on 01.11.16.
//

#ifndef LIBELECTRICITY_SIMPLEDRIVE_H
#define LIBELECTRICITY_SIMPLEDRIVE_H
/**
 * \brief Максимально упрощенная модель привода
 * За один проход выставляет текущую скорость вращения равной заданию. Управляется только по скорости вращения.
 * Текущая мощность расчитывается на основании формулы:
 * P = k * RPM^3
 */
#include "Consumer.h"

class SimpleDrive: public Consumer {
public:
    SimpleDrive(unsigned int Pnominal, unsigned int RPMnom, unsigned int Qnominal  = 0);

    virtual void calculate(std::chrono::milliseconds dTime) override;
    bool setRPM(int targetRPM);

    inline int getTargetRPM() const { return targetRPM; }
    inline int getRPM() const { return RPM; }
    inline double getK() const { return k; }

protected:
    /**
     * функция для расчета текущей мощности привода на основе задания текущего задания по скорости
     */
	void computeDrivePowers();
	/**
	 * задание на скорость вращения
	 */
    std::atomic<int> targetRPM = {0};
	/**
	 * текущие обороты привода
	 */
	std::atomic<int> RPM = {0};
	/**
	 * наклон нагрузочной характеристики привода
	 */
	std::atomic<double> k = {0};
};

#endif //LIBELECTRICITY_SIMPLEDRIVE_H
