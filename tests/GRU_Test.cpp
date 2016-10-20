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
TEST_F(GRU_Test, test1) {
    GRU gru1;
    Source gen1(2000000,1000);
    Consumer consumer1(1500000);
    gru1.addSource("Gen1", &gen1);
    gru1.addSource("Gen2", &gen1);
    gru1.addConsumer("SomeConsumer", &consumer1);
    gen1.startSource();
    gen1.setTargetU(220);
    gen1.setTargetF(50);
    gen1.setU(400);
    gen1.setF(50);
    gen1.connectToGRU();
    consumer1.connectToGRU();
    //проверка что источник и потребитель подключились
    EXPECT_TRUE(gen1.getIsConnected());
    EXPECT_TRUE(consumer1.getIsConnected());
    gru1.calculate(1);
    gru1.calculate(1);
    //проверка, что частота на шинах выставилась правильно
    EXPECT_DOUBLE_EQ(gru1.getCurrentF(), (double)50);
    //проверка, что напряжение на шинах выставилось верно
    EXPECT_DOUBLE_EQ(gru1.getCurrentU(), (double)400);

    //проверка, что напряжение на всех потребителях выставилось нормально
    EXPECT_DOUBLE_EQ(gen1.getU(), (double)400);
    EXPECT_DOUBLE_EQ(gen1.getUa(), (double)400);
    EXPECT_DOUBLE_EQ(gen1.getUb(), (double)400);
    EXPECT_DOUBLE_EQ(gen1.getUc(), (double)400);
    EXPECT_DOUBLE_EQ(consumer1.getU(), (double)400);
    EXPECT_DOUBLE_EQ(consumer1.getUa(), (double)400);
    EXPECT_DOUBLE_EQ(consumer1.getUb(), (double)400);
    EXPECT_DOUBLE_EQ(consumer1.getUc(), (double)400);
    //проверка, что частота на всех потребителях выставилось нормально
    EXPECT_DOUBLE_EQ(gen1.getf(), (double)50);
    EXPECT_DOUBLE_EQ(consumer1.getf(), (double)50);

    //проверка внутреннего сопротивления источника


//    EXPECT_DOUBLE_EQ(gen1.getRinternal(), 3.92);
    //проверка распределения мощности между источниками
    EXPECT_DOUBLE_EQ(gen1.getP(), (double)750000);
}
TEST_F(GRU_Test, test2) {
    GRU gru1;
    Source gen1(2000000,1000);
    Consumer consumer1(1500000);
    gru1.addSource("Gen1", &gen1);
    gru1.addSource("Gen2", &gen1);
    gru1.addSource("Gen3", &gen1);
    gru1.addConsumer("SomeConsumer", &consumer1);
    gen1.startSource();
    gen1.setTargetU(220);
    gen1.setTargetF(50);
    gen1.setU(400);
    gen1.setF(50);
    gen1.connectToGRU();
    consumer1.connectToGRU();

    gru1.calculate(1);
    gru1.calculate(1);

    //проверка распределения мощности между источниками
    EXPECT_DOUBLE_EQ(gen1.getP(), (double)500000);
}
TEST_F(GRU_Test, test3) {
    GRU gru1;
    Source gen1(2000000,1000);
    Source gen2(1000000,1000);
    Consumer consumer1(1500000);
    gru1.addSource("Gen1", &gen1);
    gru1.addSource("Gen2", &gen2);
    gru1.addConsumer("SomeConsumer", &consumer1);
    gen1.startSource();
    gen1.setTargetU(400);
    gen1.setTargetF(50);
    gen1.setU(400);
    gen1.setF(50);
    gen2.setTargetU(400);
    gen2.setTargetF(50);
    gen2.setU(400);
    gen2.setF(50);
    gen1.connectToGRU();
    gen2.connectToGRU();
    consumer1.connectToGRU();

    gru1.calculate(1);
    gru1.calculate(1);

    //проверка распределения мощности между источниками
    EXPECT_DOUBLE_EQ(gen1.getP(), (double)1000000);
    EXPECT_DOUBLE_EQ(gen2.getP(), (double)500000);

    gen2.disconnectToGRU();
    gru1.calculate(1);
    gru1.calculate(1);
    EXPECT_DOUBLE_EQ(gen1.getP(), (double)1500000);
    EXPECT_DOUBLE_EQ(gen2.getP(), (double)0);
}

