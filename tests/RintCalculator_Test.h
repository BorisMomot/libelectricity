//
// Created by boris on 19.10.16.
//

#ifndef LIBELECTRICITY_RINTCALCULATOR_TEST_H
#define LIBELECTRICITY_RINTCALCULATOR_TEST_H

#include <gtest/gtest.h>
#include "../RintCalculator.h"
#include <chrono>
class RintCalculator_Test: public testing::Test {
public:
    RintCalculator_Test();
    virtual ~RintCalculator_Test();
protected:
    void SetUp();
    void TearDown();
};


#endif //LIBELECTRICITY_RINTCALCULATOR_TEST_H
