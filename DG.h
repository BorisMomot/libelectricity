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

	virtual void calculateSourceF(std::chrono::milliseconds dTime) override;

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
	inline void computeJ(); //
	void computeFuelFlow(std::chrono::milliseconds dTime); //расчет уровня топлива подаваемого в дизель (ПИД регулятор)
	void computeMdv(std::chrono::milliseconds dTime); //расчет момента дизеля
	void computeMnagr(std::chrono::milliseconds dTime); //расчет текущего момента нагрузки
	void computeRPM(std::chrono::milliseconds dTime); //расчет текущей скорости вращения ДГ

	/**
	 * Внутренний ПИ-регулятор для рассчета подачи топлива в дизель
	 */
	PID pi;
	/**
	 * момент инерции ДГ
	 */
	double J = {0};

	double FuelFlow = {0}; //подача топлива
	double FuelFlow_ps = {0}; //подача топлива на предыдущем шаге
	double Mdv = {0}; //момент дизеля
	double Mdv_ps = {0}; //момент дизеля на предыдущем шаге
	double Mnagr = {0}; //момент нагрузки от генератора
	double RPM = {0}; //скорость вращения ДГ
	double RPM_ps = {0}; //скорость вращения ДГ на предыдущем шаге
};


#endif //LIBELECTRICITY_DG_H