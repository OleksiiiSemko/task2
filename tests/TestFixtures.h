#ifndef TASK2_TESTFIXTURES_H
#define TASK2_TESTFIXTURES_H
#include <gtest/gtest.h>
#include "../AnyType.h"

class TestFixtures : public testing::Test {
public:
    TestFixtures() : anyType{123} {}

    void SetUp() override {}
    void TearDown() override {}
protected:
    AnyType anyType;
};


#endif //TASK2_TESTFIXTURES_H
