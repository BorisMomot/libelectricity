//
// Created by boris on 19.10.16.
//

#include "RintCalculator_Test.h"

RintCalculator_Test::RintCalculator_Test() {}

RintCalculator_Test::~RintCalculator_Test() {}

void RintCalculator_Test::SetUp() {
    Test::SetUp();
}

void RintCalculator_Test::TearDown() {
    Test::TearDown();
}
//------------------------------------------------------
TEST_F(RintCalculator_Test, testWithoutFTarget) {
    int Pnom = 2000000;
    int Unom = 400;
    RintCalculator rCalc(Pnom, Unom);
    int Pcurrent = 1000000;
    EXPECT_DOUBLE_EQ(rCalc.calculatesinFi(1, Pcurrent, 50, 50), (double)Pcurrent/4/Pnom);
}
TEST_F(RintCalculator_Test, testWithFTarget) {
    int Pnom = 2000000;
    int Unom = 400;
    RintCalculator rCalc(Pnom, Unom);
    int Pcurrent = 1000000;
    int fTarget = 50, fCurrent = 49;
    EXPECT_DOUBLE_EQ(rCalc.calculatesinFi(1, Pcurrent, fTarget, fCurrent), (double)Pcurrent/4/Pnom - (double)(fTarget-fCurrent)*1/1000 );
    fCurrent = 51;
    EXPECT_DOUBLE_EQ(rCalc.calculatesinFi(1, Pcurrent, fTarget, fCurrent), (double)Pcurrent/4/Pnom - (double)(fTarget-fCurrent)*1/1000 );
}