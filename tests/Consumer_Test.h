//
// Created by boris on 10.11.16.
//

#ifndef LIBELECTRICITY_CONSUMER_TEST_H
#define LIBELECTRICITY_CONSUMER_TEST_H

#include <gtest/gtest.h>
#include "Consumer.h"

class Consumer_Test: public ::testing::Test {
protected:
    virtual void SetUp() override;
    virtual void TearDown() override;
};


#endif //LIBELECTRICITY_CONSUMER_TEST_H
