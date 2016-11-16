//
// Created by boris on 15.11.16.
//

#ifndef LIBELECTRICITY_PROPELLER_H
#define LIBELECTRICITY_PROPELLER_H
/**
 * \brief Модель винта
 * На основании скорости движения судна и момента от двигателя расчитывает текущую скорость
 * вращения
 */
#include "AbstractModel.h"
class Propeller: public AbstractModel {
public:
    Propeller(unsigned int Pnom);

    virtual void precalculate(std::chrono::milliseconds dTime) override {}
    virtual void calculate(std::chrono::milliseconds dTime) override;
    virtual void aftercalculation(std::chrono::milliseconds dTime) override {}

    void setMdrive(double Mdrive) { Propeller::Mdrive = Mdrive; }
    void setV(double V) { Propeller::V = V;}

    double getMdrive() const { return Mdrive;}
    double getMresistance() const { return Mresistance; }
    double getRPM() const { return RPM; }
    double getF() const { return F; }
    double getV() const { return V; }

	virtual double computeRPM(std::chrono::milliseconds dTime);
	virtual double computeForce();

protected:
    /**
     * Номинальная мощность системы
     */
    double Pmon;
    /**
     * Момент развиваемый двигателем
     */
    double Mdrive={0};
    /**
     * Момент сопротивления винта
     */
    double Mresistance={0};
    /**
     * текущая частота вращения винта
     */
    double RPM={0};
    /**
     * усилие развиваемое винтом
     */
    double F={0};
    /**
     * скорость судна м/с
     */
    double V={0};
};


#endif //LIBELECTRICITY_PROPELLER_H
