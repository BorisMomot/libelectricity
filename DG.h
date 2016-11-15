//
// Created by boris on 24.10.16.
//

#ifndef LIBELECTRICITY_DG_H
#define LIBELECTRICITY_DG_H
/**
 * \brief простая модель дизель-генератора.
 * Сильно упрощенная. Модель дизеля - аппериодическое звено первого порядка.
 * Напряжение выставляется сразу после того, как его задали (электрические процессы протекают существенно быстрее,
 * поэтому можно считать, что это не критично для модели данной точности). Нагрузка для дизеля высчитывается на
 * основании мощности подключенных потребителей. Мощность подключенных потребителей задается извне. На вход подели
 * дизеля подается текущий поток топлива. Расчет требуемой подачи происходит в ПИ-регуляторе на основании разницы
 * между текущей частотой и заданной.
 */
//todo сделать автоматическую настройку ПИ-регулятора на технический оптимум при создании модели
#include "Source.h"
#include "PID.h"
#include <chrono>

class DG: public Source {
public:
	DG(unsigned int Pnominal, unsigned int Qnominal, unsigned int Unominal=400);
	virtual ~DG(){}

	virtual void computeSourceF(std::chrono::milliseconds dTime) override;

	double getJ() const { return J; }
	double getFuelFlow() const { return FuelFlow; }
	double getMdv() const { return Mdv; }
	double getMnagr() const { return Mnagr;	}
	double getRPM() const {	return RPM; }

	void setKp(double Kp) {	pi.setKp(Kp);}
	void setTi(double Ti) { pi.setTi(Ti);}
    double getKp(){ return pi.getKp();}
    double getTi(){ return pi.getTi();}
protected:
    /**
     * расчитать инерцию ДГ (расчитывается на основании мощности генератора, причем достаточно приблизительно)
     */
	inline void computeJ(); //
    /**
     * расчет уровня топлива подаваемого в дизель (с помощью ПИД регулятора)
     * @param dTime - промежуток времени с момента предыдущего вызова функции
     */
	void computeFuelFlow(std::chrono::milliseconds dTime);
    /**
     * расчет момента дизеля
     * @param dTime - промежуток времени с момента предыдущего вызова функции
     */
	void computeMdv(std::chrono::milliseconds dTime);
    /**
     * расчет текущего момента нагрузки
     * @param dTime - промежуток времени с момента предыдущего вызова функции
     */
	void computeMnagr(std::chrono::milliseconds dTime);
    /**
     * расчет текущей скорости вращения ДГ
     * @param dTime - промежуток времени с момента предыдущего вызова функции
     */
	void computeRPM(std::chrono::milliseconds dTime);

	/**
	 * Внутренний ПИ-регулятор для рассчета подачи топлива в дизель
	 */
	PID pi;
	/**
	 * момент инерции ДГ
	 */
	double J = {0};
    /**
     * подача топлива
     */
	double FuelFlow = {0};
    /**
     * подача топлива во время предыдущего вызова функции расчета
     */
	double FuelFlow_ps = {0};
    /**
     * момент дизеля
     */
	double Mdv = {0};
    /**
     * момент дизеля во время предыдущего вызова функции расчета
     */
	double Mdv_ps = {0};
    /**
     * момент нагрузки от генератора
     */
	double Mnagr = {0};
    /**
     * текущая скорость вращения дизеля в оборотах в минуту
     */
	double RPM = {0};
    /**
     * скоростть вращения дизеля во время предыдущего вызова функции расчета
     */
	double RPM_ps = {0};
};


#endif //LIBELECTRICITY_DG_H