//
// Created by boris on 10/25/16.
//

#ifndef LIBELECTRICITY_PID_H
#define LIBELECTRICITY_PID_H

#include <chrono>

class PID {
public:
	PID(double Kp, double Ti=1);

	double getKp() const;
	bool setKp(double Kp);
	double getTi() const;
	bool setTi(double Ti);

	double computeOutput(std::chrono::milliseconds dTime, double error);

protected:
	//Настройки для ПИ-регулятора
	double Kp; //коэффициент усиления
	double Ti; //коэффициент интегрирования
	double integrMismatch = {0}; //хранит значение интегратора
};


#endif //LIBELECTRICITY_PID_H
