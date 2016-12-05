//
// Created by boris on 05.12.16.
//

#include "MultithreadWorkTest.h"
#include <chrono>


void MultithreadWorkTest::SetUp() {
    Test::SetUp();
}

void MultithreadWorkTest::TearDown() {
    Test::TearDown();
}


TEST_F(MultithreadWorkTest, IncDecrTest){
    ElModel model1;
    int count1{0}, count2{0};
    auto incrFunc = [&model1, &count1] {
        std::mutex m1;
        for (int i = 0; i<100000; ++i ){
            m1.lock();
            model1.setUbus(model1.getUbus() + 1);
            m1.unlock();
            ++count1;
        }
    };

    auto decrFunc = [&model1, &count2] {
        std::mutex m2;
        for (int i = 1; i<100000; ++i ){
            m2.lock();
            model1.setUbus(model1.getUbus() - 1);
            m2.unlock();
            ++count2;
        }
    };

    auto f1 = std::async (std::launch::async, incrFunc);
    auto f2 = std::async (std::launch::async, decrFunc);

    f1.get();
    f2.get();

    EXPECT_EQ(count1, 100000);
    EXPECT_EQ(count2, 100000-1);

    EXPECT_DOUBLE_EQ(model1.getUbus(), 1);
}

TEST_F(MultithreadWorkTest, secondTest){
    double U = 400;
    double Pinit = 10000000;
    ElModel model;
    EXPECT_TRUE(model.connectToGRU());
    EXPECT_TRUE(model.setU(U));
    model.setUbus(U);
    EXPECT_TRUE(model.setP(Pinit));
    model.calculate(std::chrono::milliseconds(1));
    EXPECT_DOUBLE_EQ(model.getPc(), Pinit/3);

    auto voltFluct = [&model, Pinit] { for (int i=0; i<10000; ++i) { model.setP(Pinit+i);} };
    auto powerGetter = [&model, Pinit] { for (int i = 0; i < 100000; ++i) {
        model.calculate(std::chrono::milliseconds(i));
        EXPECT_GE(model.getPb(), Pinit/3);
        EXPECT_LE(model.getPc(), (Pinit+10000)/3);
    }};

    auto f1 = std::async(std::launch::async, voltFluct);
    auto f2 = std::async(std::launch::async, powerGetter);

    f1.get();
    f2.get();
}