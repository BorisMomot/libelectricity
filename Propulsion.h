//
// Created by boris on 11/15/16.
//

#ifndef LIBELECTRICITY_PROPULSION_H
#define LIBELECTRICITY_PROPULSION_H

#include "AbstractModel.h"
#include "Drive.h"
#include "Propeller.h"

class Propulsion: public AbstractModel {
public:
	virtual void precalculate(std::chrono::milliseconds dTime) override {}
	virtual void calculate(std::chrono::milliseconds dTime) override;
	virtual void aftercalculation(std::chrono::milliseconds dTime) override {}
	Propulsion(Propeller *propeller, Drive *drive);

	void setVflow(double Vflow) { Propulsion::Vflow = Vflow; }
	double getVflow() const { return Vflow; }
	double getForce() const { return Force; }
	double getRPM() const { return RPM;	}

protected:
	double Vflow={0};
	double Force={0};
	double RPM={0};
	Propeller *propeller;
	Drive *drive;
};


#endif //LIBELECTRICITY_PROPULSION_H
