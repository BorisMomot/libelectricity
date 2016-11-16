//
// Created by boris on 04.11.16.
//

#ifndef LIBELECTRICITY_Q_WITHDISC_H
#define LIBELECTRICITY_Q_WITHDISC_H
/**
 * \brief Выключатель с блокировкой включения по напряжению и частоте
 * По умолчанию пороги отключения задаются равными 0. Но можно установить разные.
 */
#include "Q.h"

class Q_withDisc: public Q {
public:
    virtual bool connectTo(double U, double f) override;
    Q_withDisc(double Uborder = 0, double Fborder = 0);
    double getUborder() const {        return Uborder;    }
    double getFborder() const {        return Fborder;    }
protected:
	/**
	 * пороговые значения при которых выключатель не включается
	 */
    double Uborder, Fborder;
};


#endif //LIBELECTRICITY_Q_WITHDISC_H
