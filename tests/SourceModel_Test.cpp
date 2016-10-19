//
// Created by boris on 18.10.16.
//

#include "SourceModel_Test.h"
#include <math.h>
using namespace std;

SourceModel_Test::SourceModel_Test() {}

SourceModel_Test::~SourceModel_Test() {}

void SourceModel_Test::SetUp() {
    Test::SetUp();
}

void SourceModel_Test::TearDown() {
    Test::TearDown();
}
//------------------------------------------------------
TEST_F(SourceModel_Test, test1){
    //начальные значения
    int Pnom = 1500000;
    int Qnom = 100000;
    //проверяем как инициализируется
    EXPECT_EQ(source1.getPnominal(), Pnom);
    EXPECT_EQ(source1.getQnominal(), Qnom);
    EXPECT_EQ(source1.getSnominal(), sqrt(Pnom*Pnom+Qnom*Qnom));
    //запускаем
    EXPECT_TRUE(source1.startSource());
    EXPECT_TRUE(source1.getIsStarted());
    EXPECT_TRUE(source1.stopSource());
    EXPECT_FALSE(source1.getIsStarted());
    EXPECT_TRUE(source1.startSource());

    EXPECT_TRUE(source1.setF(50));
    EXPECT_EQ(source1.getf(), 50);

    int U = 400;
    int f = 50;
    EXPECT_TRUE(source1.setU(U));
    EXPECT_DOUBLE_EQ(source1.getU(), U);
    EXPECT_DOUBLE_EQ(source1.getUa(), U);
    EXPECT_DOUBLE_EQ(source1.getUb(), U);
    EXPECT_DOUBLE_EQ(source1.getUc(), U);
    //проверяем как устанавливается заданное напряжение
    EXPECT_TRUE(source1.setTargetU(U));
    EXPECT_DOUBLE_EQ(source1.getTargetU(), (double)U);
    EXPECT_TRUE(source1.increaseTargetVoltage());
    EXPECT_DOUBLE_EQ(source1.getTargetU(), (double)U+1);
    EXPECT_TRUE(source1.decreaseTargetVoltage());
    EXPECT_DOUBLE_EQ(source1.getTargetU(), U);
    //проверяем как устанавливается заданная частота
    EXPECT_TRUE(source1.setTargetF(f));
    EXPECT_DOUBLE_EQ(source1.getTargetF(), (double)f);
    EXPECT_TRUE(source1.increaseTargetFrequency());
    EXPECT_DOUBLE_EQ(source1.getTargetF(), (double)f+1);
    EXPECT_TRUE(source1.decreaseTargetFrequency());
    EXPECT_DOUBLE_EQ(source1.getTargetF(), f);
    //проверяем подключение к ГРУ
    EXPECT_TRUE(source1.connectToGRU());
    EXPECT_TRUE(source1.getIsConnected());
}