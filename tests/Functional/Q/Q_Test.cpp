//
// Created by boris on 04.11.16.
//

#include "Q_Test.h"

void Q_Test::SetUp() {
    Test::SetUp();
}

void Q_Test::TearDown() {
    Test::TearDown();
}
//---------------------------------------------------------------------
TEST_F(Q_Test, init){
    Q q;
    Q_withDisc q2;
    Q_withDisc q3(330, 45);
    EXPECT_FALSE(q.isIsConnected());
    EXPECT_FALSE(q2.isIsConnected());
    EXPECT_FALSE(q3.isIsConnected());

    EXPECT_DOUBLE_EQ(q2.getUborder(),0);
    EXPECT_DOUBLE_EQ(q2.getFborder(),0);
    EXPECT_DOUBLE_EQ(q3.getUborder(),330);
    EXPECT_DOUBLE_EQ(q3.getFborder(),45);
}

TEST_F(Q_Test, connectAndDisconnetc) {
    Q q;
    Q_withDisc q2;
    Q_withDisc q3(330, 45);

    EXPECT_TRUE(q.connectTo(0,0));
    EXPECT_TRUE(q2.connectTo(0,0));
    EXPECT_FALSE(q3.connectTo(0,0));

    EXPECT_TRUE(q.isIsConnected());
    EXPECT_TRUE(q2.isIsConnected());
    EXPECT_FALSE(q3.isIsConnected());

    EXPECT_TRUE(q3.connectTo(330,45));
    EXPECT_TRUE(q3.isIsConnected());

    EXPECT_TRUE(q.disconnect());
    EXPECT_TRUE(q2.disconnect());
    EXPECT_TRUE(q3.disconnect());

    EXPECT_FALSE(q.isIsConnected());
    EXPECT_FALSE(q2.isIsConnected());
    EXPECT_FALSE(q3.isIsConnected());
}