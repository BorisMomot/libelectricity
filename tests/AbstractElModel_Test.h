//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_ABSTRACTELMODEL_TEST_H
#define LIBELECTRICITY_ABSTRACTELMODEL_TEST_H

#include <gtest/gtest.h>
#include "AbstractElModel.h"
//#include <libelectricity/AbstractElModel.h>

class ConcreteAbstractElModel: public AbstractElModel{
public:
    ConcreteAbstractElModel(){}
    ~ConcreteAbstractElModel(){}
};


class AbstractElModel_Test: public testing::Test {
public:
    AbstractElModel_Test();
    virtual ~AbstractElModel_Test(){}
protected:
    void SetUp();
    void TearDown();
    ConcreteAbstractElModel testElModel;
};


#endif //LIBELECTRICITY_ABSTRACTELMODEL_TEST_H
