//
// Created by boris on 18.10.16.
//

#ifndef LIBELECTRICITY_SOURCEMODEL_TEST_H
#define LIBELECTRICITY_SOURCEMODEL_TEST_H

#include <gtest/gtest.h>
#include "Source.h"

class SourceModel_Test: public testing::Test {
public:
    SourceModel_Test();
    virtual ~SourceModel_Test();
protected:
    void SetUp();
    void TearDown();

};


#endif //LIBELECTRICITY_SOURCEMODEL_TEST_H
