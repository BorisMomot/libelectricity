//
// Created by boris on 10.11.16.
//

#include "Consumer_Test.h"

void Consumer_Test::SetUp() {
    Test::SetUp();
}
void Consumer_Test::TearDown() {
    Test::TearDown();
}
//----------------------------------------------------------
TEST_F(Consumer_Test, initTest){
    unsigned int Pnom = 15000;
    Consumer consumer1(Pnom);
    EXPECT_DOUBLE_EQ(consumer1.getPnom(), Pnom);
    EXPECT_DOUBLE_EQ(consumer1.getQnom(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getSnom(), Pnom);

    EXPECT_FALSE(consumer1.getIsConnected());
    EXPECT_DOUBLE_EQ(consumer1.getI(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getU(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getP(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getQ(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getS(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getf(), 0);

    EXPECT_DOUBLE_EQ(consumer1.getUbus(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getFbus(), 0);
}

TEST_F(Consumer_Test, connectTest){
    unsigned int Pnom = 15000;
    unsigned int U = 400;
    unsigned int f = 50;

    Consumer consumer1(Pnom);
    consumer1.setUbus(U);
    consumer1.setFbus(f);
    EXPECT_FALSE(consumer1.setU(U));
    EXPECT_FALSE(consumer1.setF(f));
    EXPECT_DOUBLE_EQ(consumer1.getU(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getf(), 0);
    EXPECT_TRUE(consumer1.connectToGRU());
    EXPECT_TRUE(consumer1.getIsConnected());
    EXPECT_TRUE(consumer1.setU(U));
    EXPECT_TRUE(consumer1.setF(f));
    EXPECT_DOUBLE_EQ(consumer1.getU(), U);
    EXPECT_DOUBLE_EQ(consumer1.getf(), f);
    consumer1.calculate(std::chrono::milliseconds(1));
    EXPECT_DOUBLE_EQ(consumer1.getI(), (double)Pnom/U);
    EXPECT_DOUBLE_EQ(consumer1.getP(), Pnom);
    EXPECT_DOUBLE_EQ(consumer1.getQ(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getS(), Pnom);
}

TEST_F(Consumer_Test, disconnectTest){
    unsigned int Pnom = 15000;
    unsigned int U = 400;
    unsigned int f = 50;

    Consumer consumer1(Pnom);
    consumer1.connectToGRU();
    consumer1.setU(U);
    consumer1.setF(f);
    consumer1.calculate(std::chrono::milliseconds(1));
    EXPECT_TRUE(consumer1.disconnectToGRU());
    consumer1.calculate(std::chrono::milliseconds(1));
    EXPECT_DOUBLE_EQ(consumer1.getI(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getP(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getQ(), 0);
    EXPECT_DOUBLE_EQ(consumer1.getS(), 0);
}