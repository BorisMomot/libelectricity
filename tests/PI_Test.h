//
// Created by boris on 29.10.16.
//

#ifndef LIBELECTRICITY_PI_TEST_H
#define LIBELECTRICITY_PI_TEST_H


#include <gtest/gtest.h>
#include "../PID.h"

class PI_Test: public testing::Test {
public:
    PI_Test() = default;
    virtual ~PI_Test() = default;

protected:
    void SetUp();
    void TearDown();
};


#endif //LIBELECTRICITY_PI_TEST_H
