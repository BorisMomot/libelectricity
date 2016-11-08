//
// Created by boris on 04.11.16.
//

#ifndef LIBELECTRICITY_Q_H
#define LIBELECTRICITY_Q_H

#include "AbstractModel.h"

class Q : public AbstractModel {
public:
    virtual void precalculate(std::chrono::milliseconds dTime) override {}
    virtual void calculate(std::chrono::milliseconds dTime) override{}
    virtual void aftercalculation(std::chrono::milliseconds dTime) override{}

    virtual bool connectTo(double U, double f);
    virtual bool disconnect();
    bool isIsConnected() const {        return isConnected;    }
protected:
    bool isConnected={0};
};


#endif //LIBELECTRICITY_Q_H
