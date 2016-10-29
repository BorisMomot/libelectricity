//
// Created by boris on 29.10.16.
//

#ifndef LIBELECTRICITY_DG_TEST_H
#define LIBELECTRICITY_DG_TEST_H

#include <gtest/gtest.h>
#include "../DG.h"

class DG_Test: public testing::Test {
public:
    DG_Test() = default;
    virtual ~DG_Test() = default;
protected:
    void SetUp();
    void TearDown();

};


#endif //LIBELECTRICITY_DG_TEST_H
