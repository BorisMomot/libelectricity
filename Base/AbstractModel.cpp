//
// Created by boris on 18.10.16.
//

#include "AbstractModel.h"

AbstractModel::AbstractModel()
{
}

AbstractModel::~AbstractModel(){}
void AbstractModel::aftercalculation(std::chrono::milliseconds dTime){}
void AbstractModel::calculate(std::chrono::milliseconds dTime){}
void AbstractModel::precalculate(std::chrono::milliseconds dTime){}

