//
// Created by boris on 04.11.16.
//

#include "Q_withDisc.h"
#include <math.h>

Q_withDisc::Q_withDisc(double Uborder, double Fborder) {
    Q_withDisc::Uborder = fabs(Uborder);
    Q_withDisc::Fborder = fabs(Fborder);
}

bool Q_withDisc::connectTo(double U, double f) {
    if (U >= Uborder && f >= Fborder){
        isConnected = true;
        return true;
    }
    else {
        return false;
    }
}
