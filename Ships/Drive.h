//
// Created by boris on 15.11.16.
//

#ifndef LIBELECTRICITY_DRIVE_H
#define LIBELECTRICITY_DRIVE_H
/**
 * \brief Простая модель двигателя.
 * На основании ошибки в задании скорости вращения и текущей скорости вращения
 * расчитывает выходной момент
 */
#include "Consumer.h"
#include "PID.h"

class Drive: public Consumer {
public:
    Drive(unsigned int Pnominal, unsigned int Qnominal);

    virtual void precalculate(std::chrono::milliseconds dTime) override { Consumer::precalculate(dTime); }
    virtual void calculate(std::chrono::milliseconds dTime) override;
    virtual void aftercalculation(std::chrono::milliseconds dTime) override { Consumer::aftercalculation(dTime); }

    double getTargetRPM() const { return targetRPM; }
	double getRPM() const { return RPM; }
	double getM() const { return M; }

	void setTargetRPM(double targetRPM) { Drive::targetRPM = targetRPM; }
	void setRPM(double RPM) { Drive::RPM = RPM; }
	/**
	 * расчитываем момент привода
	 * @return - возвращаем полученный момент привода
	 */
	virtual double computeM(std::chrono::milliseconds dTime);

protected:
    PID pi;
    std::atomic<double> targetRPM;
	std::atomic<double> RPM;
	std::atomic<double> M;
};


#endif //LIBELECTRICITY_DRIVE_H
