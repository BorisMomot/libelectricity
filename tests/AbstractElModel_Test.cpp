//
// Created by boris on 18.10.16.
//
#include "AbstractElModel_Test.h"
#include <math.h>
using namespace std;

AbstractElModel_Test::AbstractElModel_Test() {}

void AbstractElModel_Test::SetUp() {
    Test::SetUp();
    cout<<"SetUp newtest"<<endl;
}

void AbstractElModel_Test::TearDown() {
    Test::TearDown();
    cout<<"TearDown test"<<endl;
}
//------------------------------------------------------
TEST_F(AbstractElModel_Test, test220) {
    //задаем начальные условия
    int U=220;
    int f=50;
    int P=1000;
    int Q=0;
    //проверяем задание
    EXPECT_TRUE(testElModel.connectToGRU());
    EXPECT_TRUE(testElModel.setU(U));
    EXPECT_TRUE(testElModel.setF(f));
    EXPECT_TRUE(testElModel.setP(P));
    EXPECT_TRUE(testElModel.setQ(Q));
    testElModel.calculate(1);
    //проверяем как задались значения
    EXPECT_EQ(testElModel.getf(), f);
    EXPECT_EQ(testElModel.getUa(), U);
    EXPECT_EQ(testElModel.getUb(), U);
    EXPECT_EQ(testElModel.getUc(), U);
    EXPECT_FLOAT_EQ(testElModel.getPa(), (double)P/3);
    EXPECT_FLOAT_EQ(testElModel.getPb(), (double)P/3);
    EXPECT_FLOAT_EQ(testElModel.getPc(), (double)P/3);
    EXPECT_FLOAT_EQ(testElModel.getQa(), (double)Q);
    EXPECT_FLOAT_EQ(testElModel.getQb(), (double)Q);
    EXPECT_FLOAT_EQ(testElModel.getQc(), (double)Q);
    EXPECT_FLOAT_EQ(testElModel.getS(), (double)P);
    EXPECT_FLOAT_EQ(testElModel.getSa(), (double)P/3);
    EXPECT_FLOAT_EQ(testElModel.getSb(), (double)P/3);
    EXPECT_FLOAT_EQ(testElModel.getSc(), (double)P/3);
    EXPECT_FLOAT_EQ(testElModel.getI(), (double)P/U);
    EXPECT_FLOAT_EQ(testElModel.getIa(), (double)P/U/3);
    EXPECT_FLOAT_EQ(testElModel.getIb(), (double)P/U/3);
    EXPECT_FLOAT_EQ(testElModel.getIc(), (double)P/U/3);
}

TEST_F(AbstractElModel_Test, test6000) {
    //задаем начальные условия
    int U=6000;
    int f=50;
    int P=35000;
    int Q=1000;
    //проверяем задание
    EXPECT_TRUE(testElModel.connectToGRU());
    EXPECT_TRUE(testElModel.setU(U));
    EXPECT_TRUE(testElModel.setF(f));
    EXPECT_TRUE(testElModel.setP(P));
    EXPECT_TRUE(testElModel.setQ(Q));
    testElModel.calculate(1);
    //проверяем как задались значения
    EXPECT_EQ(testElModel.getf(), f);
    EXPECT_EQ(testElModel.getUa(), U);
    EXPECT_EQ(testElModel.getUb(), U);
    EXPECT_EQ(testElModel.getUc(), U);
    EXPECT_FLOAT_EQ(testElModel.getPa(), (double)P/3);
    EXPECT_FLOAT_EQ(testElModel.getPb(), (double)P/3);
    EXPECT_FLOAT_EQ(testElModel.getPc(), (double)P/3);
    EXPECT_FLOAT_EQ(testElModel.getQa(), (double)Q/3);
    EXPECT_FLOAT_EQ(testElModel.getQb(), (double)Q/3);
    EXPECT_FLOAT_EQ(testElModel.getQc(), (double)Q/3);
    EXPECT_FLOAT_EQ(testElModel.getS(), (double)sqrt(P*P+Q*Q));
    EXPECT_FLOAT_EQ(testElModel.getSa(), (double)sqrt(P*P+Q*Q)/3);
    EXPECT_FLOAT_EQ(testElModel.getSb(), (double)sqrt(P*P+Q*Q)/3);
    EXPECT_FLOAT_EQ(testElModel.getSc(), (double)sqrt(P*P+Q*Q)/3);
    EXPECT_FLOAT_EQ(testElModel.getI(), (double)P/U);
    EXPECT_FLOAT_EQ(testElModel.getIa(), (double)P/U/3);
    EXPECT_FLOAT_EQ(testElModel.getIb(), (double)P/U/3);
    EXPECT_FLOAT_EQ(testElModel.getIc(), (double)P/U/3);
}
