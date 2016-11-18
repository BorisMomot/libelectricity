//
// Created by boris on 20.10.16.
//

#ifndef LIBELECTRICITY_GRU_TEST_H
#define LIBELECTRICITY_GRU_TEST_H
#include <gtest/gtest.h>
#include "GRU.h"

class GRU_Test: public ::testing::Test {
public:
    GRU_Test();
protected:
    void SetUp();
    void TearDown();
};


#endif //LIBELECTRICITY_GRU_TEST_H
