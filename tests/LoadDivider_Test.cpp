//
// Created by boris on 20.10.16.
//

#include "LoadDivider_Test.h"

LoadDivider_Test::LoadDivider_Test() {}

LoadDivider_Test::~LoadDivider_Test() {}

void LoadDivider_Test::SetUp() {
    Test::SetUp();
}

void LoadDivider_Test::TearDown() {
    Test::TearDown();
}

//-------------------------------------------------
TEST_F(LoadDivider_Test, test1) {
    EXPECT_DOUBLE_EQ(LoadDivider::calculateSourceLoad(10000, 0.9, 0.105, 2), 4);
}
