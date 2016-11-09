//
// Created by boris on 29.10.16.
//

#include "DG_Test.h"

void DG_Test::SetUp() {
    Test::SetUp();
}

void DG_Test::TearDown() {
    Test::TearDown();
}

//-----------------------------------------
TEST_F(DG_Test, check_Inicialisation){
    unsigned int Pnom = 1500000, Qnom = 100000;
    DG dg(Pnom,Qnom);

    EXPECT_DOUBLE_EQ(dg.getf(), 0);
    EXPECT_DOUBLE_EQ(dg.getFuelFlow(), 0);
    EXPECT_DOUBLE_EQ(dg.getRPM(), 0);
    EXPECT_DOUBLE_EQ(dg.getMdv(), 0);
    EXPECT_DOUBLE_EQ(dg.getMnagr(),0);
    double J = (double)Pnom*(double)Pnom/20/314/314;
    EXPECT_DOUBLE_EQ(dg.getJ(), J);
}

TEST_F(DG_Test, check_PI_Settings){
    unsigned int Pnom = 1500000, Qnom = 100000;
    DG dg(Pnom,Qnom);
    EXPECT_DOUBLE_EQ(dg.getKp(), 0);
    EXPECT_DOUBLE_EQ(dg.getTi(), 1);
    double kp = 1.3, Ti = 2;
    dg.setKp(kp);
    dg.setTi(Ti);
    EXPECT_DOUBLE_EQ(dg.getKp(), kp);
    EXPECT_DOUBLE_EQ(dg.getTi(), Ti);
}

TEST_F(DG_Test, check_Step_Calculation){
    unsigned int Pnom = 1500000, Qnom = 100000;
    DG dg(Pnom,Qnom);
    dg.startSource();

    double kp = 1, Ti = 2;
    dg.setKp(kp);
    dg.setTi(Ti);

    std::chrono::milliseconds dTime(1);
    dg.calculateSourceF(dTime);
    EXPECT_DOUBLE_EQ(dg.getf(), 0);
    EXPECT_DOUBLE_EQ(dg.getFuelFlow(), 0);
    EXPECT_DOUBLE_EQ(dg.getRPM(), 0);
    EXPECT_DOUBLE_EQ(dg.getMdv(), 0);
    EXPECT_DOUBLE_EQ(dg.getMnagr(),0);
}


