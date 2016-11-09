//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_ABSTRACTMODEL_H
#define LIBELECTRICITY_ABSTRACTMODEL_H

#include <chrono>

class AbstractModel
{
public:
    AbstractModel();
    virtual void precalculate(std::chrono::milliseconds dTime) = 0;
    virtual void calculate(std::chrono::milliseconds dTime) = 0;
    virtual void aftercalculation(std::chrono::milliseconds dTime) = 0;
    virtual ~AbstractModel();
};


#endif //LIBELECTRICITY_ABSTRACTMODEL_H
