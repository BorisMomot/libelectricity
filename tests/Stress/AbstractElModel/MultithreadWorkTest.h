//
// Created by boris on 05.12.16.
//

#ifndef LIBELECTRICITY_MULTITHREADWORKTEST_H
#define LIBELECTRICITY_MULTITHREADWORKTEST_H

#include <gtest/gtest.h>
#include <AbstractElModel.h>
#include <future>

class ElModel: public AbstractElModel {
public:
    ElModel(){};
    ~ElModel(){};
};

class MultithreadWorkTest: public ::testing::Test {
protected:
    void SetUp() override;

    void TearDown() override;
};


#endif //LIBELECTRICITY_MULTITHREADWORKTEST_H
