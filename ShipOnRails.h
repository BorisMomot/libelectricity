//
// Created by boris on 15.11.16.
//

#ifndef LIBELECTRICITY_SHIPONRAILS_H
#define LIBELECTRICITY_SHIPONRAILS_H
/**
 * \brief Модель судна движущаяся только по прямой
 * Предельно простая модель судна. Исходя из номинальной скорости и мощности движения получаем номинальное сопротивление
 * корпуса движению. Принимаем характеристику движения кубической и расчитываем для всех остальных значений скорости.
 */
#include "Propulsion.h"
#include "Convinience_functions.h"
#include <map>

class ShipOnRails: public AbstractModel {
public:
    virtual void precalculate(std::chrono::milliseconds dTime) override;
    virtual void calculate(std::chrono::milliseconds dTime) override;
    virtual void aftercalculation(std::chrono::milliseconds dTime) override;

	bool addPropulsion(std::string& name, Propulsion* propulsion);

	double computeSpeed();

protected:
    std::map<std::string, Propulsion*> propulsions;
	/**
	 * Скорость судна
	 */
	double Speed;
};


#endif //LIBELECTRICITY_SHIPONRAILS_H
