//
// Created by boris on 18.10.16.
//

#include "AbstractModel.h"

AbstractModel::AbstractModel()
{
}

AbstractModel::~AbstractModel(){}
void AbstractModel::aftercalculation(unsigned int dTime){}
void AbstractModel::calculate(unsigned int dTime){}
void AbstractModel::precalculate(unsigned int dTime){}

