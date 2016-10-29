//
// Created by boris on 29.10.16.
//

#include "PI_Test.h"

void PI_Test::SetUp() {
    Test::SetUp();
}

void PI_Test::TearDown() {
    Test::TearDown();
}

//------------------------------------------
//Проверяем правильность инициализации значений ПИ регулятора
TEST_F(PI_Test, check_coef_Settings) {
    PID pi(1);
    EXPECT_DOUBLE_EQ(pi.getKp(), 1.0);
    EXPECT_DOUBLE_EQ(pi.getTi(), 1.0);

    pi.setKp(17);
    pi.setTi(87);
    EXPECT_DOUBLE_EQ(pi.getKp(), 17.0);
    EXPECT_DOUBLE_EQ(pi.getTi(), 87.0);
}
//Проверяем, что ПИ-регулятор считает правильно
TEST_F(PI_Test, check_step_Calculation){
    PID pi(1);
    unsigned int dTime = 5; //временной шаг
    double error = 4; //ошибка между заданием и фактиеским
    double Integrator = 0;
    double outputFirstStep = pi.getKp()*(error+dTime*error/pi.getTi());
    Integrator = dTime*error/pi.getTi();
    EXPECT_DOUBLE_EQ(pi.computeOutput(dTime, error), outputFirstStep);

    double outputSecondStep = pi.getKp()*(error + Integrator + dTime*error/pi.getTi());
    Integrator += dTime*error/pi.getTi();
    EXPECT_DOUBLE_EQ(pi.computeOutput(dTime, error), outputSecondStep);

    double outputThirdStep = pi.getKp()*(error + Integrator + dTime*error/pi.getTi());
    EXPECT_DOUBLE_EQ(pi.computeOutput(dTime, error), outputThirdStep);
}
