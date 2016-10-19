//
// Created by boris on 20.10.16.
//

#ifndef LIBELECTRICITY_LOADDIVIDER_TEST_H
#define LIBELECTRICITY_LOADDIVIDER_TEST_H
#include <gtest/gtest.h>
#include "../LoadDivider.h"

class LoadDivider_Test: public testing::Test {
public:
    LoadDivider_Test();

    virtual ~LoadDivider_Test();

protected:
    void SetUp();
    void TearDown();
};


#endif //LIBELECTRICITY_LOADDIVIDER_TEST_H
