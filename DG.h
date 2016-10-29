//
// Created by boris on 24.10.16.
//

#ifndef LIBELECTRICITY_DG_H
#define LIBELECTRICITY_DG_H

#include "Source.h"
#include "PID.h"

class DG: public Source {
public:
	DG(unsigned int Pnominal, unsigned int Qnominal, unsigned int Unominal=400);
	virtual ~DG(){}

	virtual void calculateSourceF(unsigned int dTime) override;

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
	void computeFuelFlow(unsigned int dTime); //расчет уровня топлива подаваемого в дизель (ПИД регулятор)
	void computeMdv(unsigned int dTime); //расчет момента дизеля
	void computeMnagr(unsigned int dTime); //расчет текущего момента нагрузки
	void computeRPM(unsigned int dTime); //расчет текущей скорости вращения ДГ

	PID pi;
	double J = {0}; //момент инерции ДГ
	double FuelFlow = {0}; //подача топлива
	double FuelFlow_ps = {0}; //подача топлива на предыдущем шаге
	double Mdv = {0}; //момент дизеля
	double Mdv_ps = {0}; //момент дизеля на предыдущем шаге
	double Mnagr = {0}; //момент нагрузки от генератора
	double RPM = {0}; //скорость вращения ДГ
	double RPM_ps = {0}; //скорость вращения ДГ на предыдущем шаге
};


#endif //LIBELECTRICITY_DG_H