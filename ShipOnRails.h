//
// Created by boris on 15.11.16.
//

#ifndef LIBELECTRICITY_SHIPONRAILS_H
#define LIBELECTRICITY_SHIPONRAILS_H

#include "Drive.h"
#include "Propeller.h"
#include <map>

class ShipOnRails: public AbstractModel {
public:
    virtual void precalculate(std::chrono::milliseconds dTime) override {}
    virtual void calculate(std::chrono::milliseconds dTime) override;
    virtual void aftercalculation(std::chrono::milliseconds dTime) override {}

protected:
    std::map<std::string, Drive*> drives;
    std::map<std::string, Propeller*> propellers;


};


#endif //LIBELECTRICITY_SHIPONRAILS_H
