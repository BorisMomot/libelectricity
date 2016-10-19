//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_ABSTRACTMODEL_H
#define LIBELECTRICITY_ABSTRACTMODEL_H


class AbstractModel
{
public:
    AbstractModel();
    virtual void precalculate(unsigned int dTime) = 0;
    virtual void calculate(unsigned int dTime) = 0;
    virtual void aftercalculation(unsigned int dTime) = 0;
    virtual ~AbstractModel();
};


#endif //LIBELECTRICITY_ABSTRACTMODEL_H
