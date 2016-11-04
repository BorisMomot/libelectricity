//
// Created by boris on 04.11.16.
//

#ifndef LIBELECTRICITY_Q_TEST_H
#define LIBELECTRICITY_Q_TEST_H

#include "../Q.h"
#include "../Q_withDisc.h"
#include <gtest/gtest.h>

class Q_Test: public ::testing::Test {
protected:
    virtual void SetUp() override;
    virtual void TearDown() override;
};


#endif //LIBELECTRICITY_Q_TEST_H
