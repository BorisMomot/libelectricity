//
// Created by boris on 18.10.16.
//
#include <gtest/gtest.h>
#include "AbstractElModel_Test.h"

//#include "Test1.h"
//#include "TestAbstractFactory.h"
//#include "TestStates.h"
//#include "turtleGMock/Painter.h"
//#include "MockTurtle.h"

//using ::testing::AtLeast;

//TEST(PainterTest, PainterTest_CanDrawSomething_Test) {
//MockTurtle turtle1;
//EXPECT_CALL(turtle1, PenDown())
//.Times(AtLeast(1));
//Painter painter(turtle1);
//EXPECT_TRUE(painter.DrawSquare(0,0,10,20));
//}

int main (int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
