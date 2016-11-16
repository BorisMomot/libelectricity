//
// Created by boris on 10/25/16.
//

#ifndef LIBELECTRICITY_PID_H
#define LIBELECTRICITY_PID_H
/**
 * \brief модель ПИ-регулятора
 * ПИ-регулятор работает с перменным шагом. Защита от переполнения интегратора сделана на уровне +/-1e300,
 * дальше значение интегратора не растет, а остается на этой отметке.
 * Ошибка на входе должна быть по модулю меньше 1e200. Если она больше - сигнал ошибки принимается равным
 * 1e200
 * Передаточная функция:
 * W(s) = Kp(1+1/(s*Ti))
 */
#include <chrono>

class PID {
public:
	PID(double Kp, double Ti=1);

	double getKp() const;
	bool setKp(double Kp);
	double getTi() const;
	bool setTi(double Ti);
	/**
	 * расчитываем выход ПИ-регулятора
	 * @param dTime - время с момента последнего вызова функции
	 * @param error - ошибка между заданием и текущим значением
	 * @return - возвращает значение полученное на выходе ПИ-регулятора
	 */
	double computeOutput(std::chrono::milliseconds dTime, double error);

protected:
	//Настройки для ПИ-регулятора
	/**
	 * Коэффициент усиления
	 */
	double Kp;
	/**
	 * Интегральная составляющая регулятора
	 */
	double Ti;
	/**
	 * Значение интегратора
	 */
	double integrMismatch = {0};
};


#endif //LIBELECTRICITY_PID_H
