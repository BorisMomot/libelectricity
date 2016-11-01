//
// Created by boris on 01.11.16.
//

#include "SimpleDrive_Test.h"

SimpleDrive_Test::SimpleDrive_Test() {}

void SimpleDrive_Test::SetUp() {
    Test::SetUp();
}

void SimpleDrive_Test::TearDown() {
    Test::TearDown();
}
//-----------------------------------------------------------------
TEST_F(SimpleDrive_Test, initialization){
    int Pnom = 2000000;
    int RPMnom = 200;
    SimpleDrive sDrive(Pnom, RPMnom);
    EXPECT_DOUBLE_EQ(sDrive.getK(), (double)Pnom / RPMnom / RPMnom / RPMnom);
}

TEST_F(SimpleDrive_Test, checkRPM){
    int Pnom = 2000000;
    int RPMnom = 200;
    double U = 400;
    double f = 50;
    SimpleDrive sDrive(Pnom, RPMnom);
    EXPECT_TRUE(sDrive.connectToGRU());
    EXPECT_TRUE(sDrive.setU(U));
    EXPECT_TRUE(sDrive.setF(f));
    EXPECT_TRUE(sDrive.setRPM(100));
    sDrive.calculate(1);
    EXPECT_DOUBLE_EQ(sDrive.getRPM(), (double)100);
    sDrive.disconnectToGRU();
    sDrive.calculate(1);
    EXPECT_DOUBLE_EQ(sDrive.getRPM(), (double)0);
}

TEST_F(SimpleDrive_Test, checkPower){
    int Pnom = 2000000;
    int RPMnom = 200;
    double U = 400;
    double f = 50;
    SimpleDrive sDrive(Pnom, RPMnom);
    EXPECT_TRUE(sDrive.connectToGRU());
    EXPECT_TRUE(sDrive.setU(U));
    EXPECT_TRUE(sDrive.setF(f));
    EXPECT_TRUE(sDrive.setRPM(RPMnom));
    sDrive.calculate(1);
    EXPECT_DOUBLE_EQ(sDrive.getP(), (double)Pnom);
    EXPECT_DOUBLE_EQ(sDrive.getPa(), (double)Pnom/3);
    //отключаем от ГРУ
    sDrive.disconnectToGRU();
    sDrive.calculate(1);
    EXPECT_DOUBLE_EQ(sDrive.getP(), 0);
    EXPECT_DOUBLE_EQ(sDrive.getPa(), 0);
}

TEST_F(SimpleDrive_Test, checkCurrents){
    int Pnom = 2000000;
    int RPMnom = 200;
    double U = 400;
    double f = 50;
    SimpleDrive sDrive(Pnom, RPMnom);
    EXPECT_TRUE(sDrive.connectToGRU());
    EXPECT_TRUE(sDrive.setU(U));
    EXPECT_TRUE(sDrive.setF(f));
    EXPECT_TRUE(sDrive.setRPM(RPMnom));
    sDrive.calculate(1);
    EXPECT_DOUBLE_EQ(sDrive.getI(), (double)Pnom/U);
    EXPECT_DOUBLE_EQ(sDrive.getIa(), (double)Pnom/U/3);
    //отключаем от ГРУ
    sDrive.disconnectToGRU();
    sDrive.calculate(1);
    EXPECT_DOUBLE_EQ(sDrive.getI(), 0);
    EXPECT_DOUBLE_EQ(sDrive.getIa(), 0);
}
