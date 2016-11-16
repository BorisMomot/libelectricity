//
// Created by boris on 01.11.16.
//

#ifndef LIBELECTRICITY_SIMPLEDRIVE_TEST_H
#define LIBELECTRICITY_SIMPLEDRIVE_TEST_H

#include <gtest/gtest.h>
#include "SimpleDrive.h"

class SimpleDrive_Test: public testing::Test {
public:
    SimpleDrive_Test();

protected:
    virtual void SetUp() override;
    virtual void TearDown() override;
};


#endif //LIBELECTRICITY_SIMPLEDRIVE_TEST_H
