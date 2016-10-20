//
// Created by boris on 20.10.16.
//

#include "LoadDivider_Test.h"

LoadDivider_Test::LoadDivider_Test() {}

LoadDivider_Test::~LoadDivider_Test() {}

void LoadDivider_Test::SetUp() {
    Test::SetUp();
}

void LoadDivider_Test::TearDown() {
    Test::TearDown();
}

//-------------------------------------------------
TEST_F(LoadDivider_Test, testTwoSourcees) {
    int Ptotal = 10000, numberOfSources = 2;
    double Rsum = 0.9, R1 = 0.105;
    EXPECT_DOUBLE_EQ(LoadDivider::calculateSourceLoad(Ptotal, Rsum, R1, numberOfSources), (double)(Rsum-R1)/Rsum/(numberOfSources-1)*Ptotal);
}

TEST_F(LoadDivider_Test, testThreeSourcees) {
    int Ptotal = 10000, numberOfSources = 3;
    double Rsum = 0.9, R1 = 0.105;
    EXPECT_DOUBLE_EQ(LoadDivider::calculateSourceLoad(Ptotal, Rsum, R1, numberOfSources), (double)(Rsum-R1)/Rsum/(numberOfSources-1)*Ptotal);
}