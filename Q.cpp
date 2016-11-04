//
// Created by boris on 04.11.16.
//

#include "Q.h"

bool Q::connectTo(double U, double f) {
    isConnected = true;
    return true;
}
bool Q::disconnect() {
    isConnected = false;
    return true;
}
