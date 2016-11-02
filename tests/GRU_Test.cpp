//
// Created by boris on 20.10.16.
//

#include "GRU_Test.h"


GRU_Test::GRU_Test() {}

void GRU_Test::SetUp() {
    Test::SetUp();
}

void GRU_Test::TearDown() {
    Test::TearDown();
}

//--------------------------------------
TEST_F(GRU_Test, CheckInitialisation) {
    GRU gru1;
    EXPECT_DOUBLE_EQ(gru1.getCurrentConsumptionP(), 0);
    EXPECT_DOUBLE_EQ(gru1.getCurrentConsumptionQ(), 0);
    EXPECT_DOUBLE_EQ(gru1.getCurrentConsumptionS(), 0);
    //проверяем сколько мощности можно подключить к шинам ГРУ, чтобы не перегрузить источники
    EXPECT_DOUBLE_EQ(gru1.getPnomSources(), 0);
    EXPECT_DOUBLE_EQ(gru1.getQnomSources(), 0);
    EXPECT_DOUBLE_EQ(gru1.getSnomSources(), 0);
    //проверяем как расчитался резерв мощности
    EXPECT_DOUBLE_EQ(gru1.getPreserv(), 0);
    EXPECT_DOUBLE_EQ(gru1.getQreserv(), 0);
    EXPECT_DOUBLE_EQ(gru1.getSreserv(), 0);
    gru1.calculate(1);
    gru1.calculate(1);
    EXPECT_DOUBLE_EQ(gru1.getCurrentConsumptionP(), 0);
    EXPECT_DOUBLE_EQ(gru1.getCurrentConsumptionQ(), 0);
    EXPECT_DOUBLE_EQ(gru1.getCurrentConsumptionS(), 0);
    //проверяем сколько мощности можно подключить к шинам ГРУ, чтобы не перегрузить источники
    EXPECT_DOUBLE_EQ(gru1.getPnomSources(), 0);
    EXPECT_DOUBLE_EQ(gru1.getQnomSources(), 0);
    EXPECT_DOUBLE_EQ(gru1.getSnomSources(), 0);
    //проверяем как расчитался резерв мощности
    EXPECT_DOUBLE_EQ(gru1.getPreserv(), 0);
    EXPECT_DOUBLE_EQ(gru1.getQreserv(), 0);
    EXPECT_DOUBLE_EQ(gru1.getSreserv(), 0);
}

TEST_F(GRU_Test, checkNetworkParametersANDTwoSourcesDividing) {
    double PnomSource = 2000000;
    double QnomSource = 1000;
    double SnomSource = sqrt((double)PnomSource*(double)PnomSource + (double)QnomSource*(double)QnomSource);
    double PnomConsumption = 1500000;
    int f = 50;
    int U = 400;
    GRU gru1;
    Source gen1(PnomSource,QnomSource);
    Consumer consumer1(PnomConsumption);
    gru1.addSource("Gen1", &gen1);
    gru1.addSource("Gen2", &gen1);
    gru1.addConsumer("SomeConsumer", &consumer1);
    gen1.startSource();
    gen1.setTargetU(U);
    gen1.setTargetF(f);
    gen1.setU(U);
    gen1.setF(f);
    gen1.connectToGRU();
    consumer1.connectToGRU();
    //проверка что источник и потребитель подключились
    EXPECT_TRUE(gen1.getIsConnected());
    EXPECT_TRUE(consumer1.getIsConnected());
    gru1.calculate(1);
    gru1.calculate(1);
    //проверка, что частота на шинах выставилась правильно
    EXPECT_DOUBLE_EQ(gru1.getCurrentF(), (double)f);
    //проверка, что напряжение на шинах выставилось верно
    EXPECT_DOUBLE_EQ(gru1.getCurrentU(), (double)U);
    //проверка, что напряжение на всех потребителях выставилось нормально
    EXPECT_DOUBLE_EQ(gen1.getU(), (double)U);
    EXPECT_DOUBLE_EQ(gen1.getUa(), (double)U);
    EXPECT_DOUBLE_EQ(gen1.getUb(), (double)U);
    EXPECT_DOUBLE_EQ(gen1.getUc(), (double)U);
    EXPECT_DOUBLE_EQ(consumer1.getU(), (double)U);
    EXPECT_DOUBLE_EQ(consumer1.getUa(), (double)U);
    EXPECT_DOUBLE_EQ(consumer1.getUb(), (double)U);
    EXPECT_DOUBLE_EQ(consumer1.getUc(), (double)U);
    //проверка, что частота на всех потребителях выставилось нормально
    EXPECT_DOUBLE_EQ(gen1.getf(), (double)f);
    EXPECT_DOUBLE_EQ(consumer1.getf(), (double)f);
    //проверка распределения мощности между источниками
    EXPECT_DOUBLE_EQ(gen1.getP(), (double)750000);
}


TEST_F(GRU_Test, checkTwoSourcesDividing) {
    double PnomSource = 2000000;
    double QnomSource = 1000;
    double PnomConsumption = 1500000;
    int f = 50;
    int U = 400;
    GRU gru1;
    Source gen1(PnomSource,QnomSource);
    Consumer consumer1(PnomConsumption);
    gru1.addSource("Gen1", &gen1);
    gru1.addSource("Gen2", &gen1);
    gru1.addConsumer("SomeConsumer", &consumer1);
    gen1.startSource();
    gen1.setTargetU(U);
    gen1.setTargetF(f);
    gen1.setU(U);
    gen1.setF(f);
    gen1.connectToGRU();
    consumer1.connectToGRU();
    //проверка что источник и потребитель подключились
    EXPECT_TRUE(gen1.getIsConnected());
    EXPECT_TRUE(consumer1.getIsConnected());
    gru1.calculate(1);
    gru1.calculate(1);
    //проверка распределения мощности между источниками
    EXPECT_DOUBLE_EQ(gen1.getP(), (double)750000);
}


TEST_F(GRU_Test, checkThreeSourcesDividing) {
    double PnomSource = 2000000;
    double QnomSource = 1000;
    double SnomSource = sqrt((double)PnomSource*(double)PnomSource + (double)QnomSource*(double)QnomSource);
    double PnomConsumption = 1500000;
    int f = 50;
    int U = 400;
    GRU gru1;
    Source gen1(PnomSource,QnomSource);
    Consumer consumer1(PnomConsumption);
    gru1.addSource("Gen1", &gen1);
    gru1.addSource("Gen2", &gen1);
    gru1.addSource("Gen3", &gen1);
    gru1.addConsumer("SomeConsumer", &consumer1);
    gen1.startSource();
    gen1.setTargetU(U);
    gen1.setTargetF(f);
    gen1.setU(U);
    gen1.setF(f);
    gen1.connectToGRU();
    consumer1.connectToGRU();
    gru1.calculate(1);
    gru1.calculate(1);
    //проверка распределения мощности между источниками
    EXPECT_DOUBLE_EQ(gen1.getP(), (double)500000);
}
TEST_F(GRU_Test, checkLoadDividingAfterDisconnectionBetweenDifferentSources) {
    double PnomSource = 2000000;
    double QnomSource = 1000;
    double SnomSource = sqrt((double)PnomSource*(double)PnomSource + (double)QnomSource*(double)QnomSource);
    double PnomConsumption = 1500000;
    int f = 50;
    int U = 400;
    GRU gru1;
    Source gen1(PnomSource,QnomSource);
    Source gen2(PnomSource/2,QnomSource);
    Consumer consumer1(PnomConsumption);
    gru1.addSource("Gen1", &gen1);
    gru1.addSource("Gen2", &gen2);
    gru1.addConsumer("SomeConsumer", &consumer1);
    gen1.startSource();
    gen1.setTargetU(U);
    gen1.setTargetF(f);
    gen1.setU(U);
    gen1.setF(f);
    gen2.setTargetU(U);
    gen2.setTargetF(f);
    gen2.setU(U);
    gen2.setF(f);
    gen1.connectToGRU();
    gen2.connectToGRU();
    consumer1.connectToGRU();

    gru1.calculate(1);
    gru1.calculate(1);

    //проверка распределения мощности между источниками
    EXPECT_DOUBLE_EQ(gen1.getP(), (double)PnomConsumption*2/3);
    EXPECT_DOUBLE_EQ(gen2.getP(), (double)PnomConsumption*1/3);

    gen2.disconnectToGRU();
    gru1.calculate(1);
    gru1.calculate(1);
    EXPECT_DOUBLE_EQ(gen1.getP(), (double)PnomConsumption);
    EXPECT_DOUBLE_EQ(gen2.getP(), (double)0);
}

TEST_F(GRU_Test, CheckPowerReserws) {
    double PnomSource = 2000000;
    double QnomSource = 1000;
    double SnomSource = sqrt((double)PnomSource*(double)PnomSource + (double)QnomSource*(double)QnomSource);
    double PnomConsumption = 1500000;
    int f = 50;
    int U = 400;
    GRU gru1;
    Source gen1(PnomSource, QnomSource);
    Consumer consumer1(PnomConsumption);
    gru1.addSource("Gen1", &gen1);
    gru1.addConsumer("SomeConsumer", &consumer1);
    gen1.startSource();
    gen1.setTargetU(U);
    gen1.setTargetF(f);
    gen1.setU(U);
    gen1.setF(f);
    gen1.connectToGRU();
    consumer1.connectToGRU();
    //проверка что источник и потребитель подключились
    EXPECT_TRUE(gen1.getIsConnected());
    EXPECT_TRUE(consumer1.getIsConnected());
    gru1.calculate(1);
    gru1.calculate(1);
    EXPECT_DOUBLE_EQ(gru1.getCurrentConsumptionP(), PnomConsumption);
    EXPECT_DOUBLE_EQ(gru1.getCurrentConsumptionQ(), 0);
    EXPECT_DOUBLE_EQ(gru1.getCurrentConsumptionS(), PnomConsumption);
    //проверяем сколько мощности можно подключить к шинам ГРУ, чтобы не перегрузить источники
    EXPECT_DOUBLE_EQ(gru1.getPnomSources(), PnomSource);
    EXPECT_DOUBLE_EQ(gru1.getQnomSources(), QnomSource);
    EXPECT_DOUBLE_EQ(gru1.getSnomSources(), SnomSource);
    //проверяем как расчитался резерв мощности
    EXPECT_DOUBLE_EQ(gru1.getPreserv(), PnomSource - PnomConsumption);
    EXPECT_DOUBLE_EQ(gru1.getQreserv(), QnomSource);
    EXPECT_DOUBLE_EQ(gru1.getSreserv(), SnomSource - PnomConsumption);
}