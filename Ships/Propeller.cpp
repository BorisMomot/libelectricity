//
// Created by boris on 15.11.16.
//

#include "Propeller.h"

Propeller::Propeller(unsigned int Pnom): Pmon(Pnom) {
}

void Propeller::calculate(std::chrono::milliseconds dTime) {
}

double Propeller::computeRPM(std::chrono::milliseconds dTime) {
	return 0;
}

double Propeller::computeForce() {
	return 0;
}
