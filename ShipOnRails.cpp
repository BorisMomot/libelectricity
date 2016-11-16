//
// Created by boris on 15.11.16.
//

#include "ShipOnRails.h"

using namespace std;

void ShipOnRails::precalculate(std::chrono::milliseconds dTime) {
	auto precalc = [dTime] (AbstractModel* model){ model->precalculate(dTime);};
	doSmthWithMapValues<Propulsion>(propulsions, precalc);

}

void ShipOnRails::calculate(std::chrono::milliseconds dTime) {
	auto calc = [dTime] (AbstractModel* model){ model->calculate(dTime);};
	doSmthWithMapValues<Propulsion>(propulsions, calc);
}

void ShipOnRails::aftercalculation(std::chrono::milliseconds dTime) {
	auto aftercalc = [dTime] (AbstractModel* model){ model->aftercalculation(dTime);};
	doSmthWithMapValues<Propulsion>(propulsions, aftercalc);
}

bool ShipOnRails::addPropulsion(std::string &name, Propulsion *propulsion) {
	propulsions.insert(pair<string, Propulsion*> (name, propulsion));
	return false;
}

double ShipOnRails::computeSpeed() {
	return 0;
}



