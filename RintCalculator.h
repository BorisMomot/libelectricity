//
// Created by boris on 19.10.16.
//

#ifndef LIBELECTRICITY_RINTCALCULATOR_H
#define LIBELECTRICITY_RINTCALCULATOR_H

class RintCalculator {
public:
    RintCalculator(unsigned int Pnominal, unsigned int Unominal, double EfficiencyNominal=0.98, unsigned int Kkonstractional=1);
    virtual double calculateRinternal(unsigned int dTime, double Pcurrent, double Ftarget, double Fcurrent, double Pkr=0);
    virtual double calculatesinFi(unsigned int dTime, double Pcurrent, double Ftarget, double Fcurrent, double Pkr=0);//функция для расчета угла между магнитным полем ротора и статора
protected:
    unsigned int Pnom, Unom, Kkonstr;
    double EfficiencyNom;
};

#endif //LIBELECTRICITY_RINTCALCULATOR_H
