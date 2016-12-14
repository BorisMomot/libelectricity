//
// Created by boris on 11/15/16.
//

#include "Propulsion.h"
Propulsion::Propulsion(Propeller *propeller, Drive *drive) : propeller(propeller), drive(drive) {}

void Propulsion::calculate(std::chrono::milliseconds dTime) {
	propeller->setV(Vflow);
	drive->setRPM(propeller->getRPM());
	drive->computeM(dTime);
	propeller->setMdrive(drive->getM());
	propeller->computeRPM(dTime);
	propeller->computeForce();
	//пока вот так.. не оптимально.. зато понятно
	RPM = propeller->getRPM();
	Force = propeller->getF();

	propeller->calculate(dTime);
	drive->calculate(dTime);
}

