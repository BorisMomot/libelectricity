//
// Created by boris on 15.11.16.
//

#include "Drive.h"

Drive::Drive(unsigned int Pnominal, unsigned int Qnominal) : Consumer(Pnominal, Qnominal), pi(1) {}

void Drive::calculate(std::chrono::milliseconds dTime) {
    Consumer::calculate(dTime);
}

double Drive::computeM(std::chrono::milliseconds dTime) {
	return 0;
}
