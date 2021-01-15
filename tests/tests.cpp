#include <gtest/gtest.h>
#include <typeinfo>
#include "../AnyType.h"
#include "TestFixtures.h"
#include "../utils.h"

TEST (AnyTypeTests, CreateIntegerByConstructor) {
    int test_value = 234;
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.getType(), Type::Integer);
}

TEST (AnyTypeTests, CreateLongIntegerByConstructor) {
    long int test_value{1242123};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.getType(), Type::LongInteger);
}

TEST (AnyTypeTests, CreateUnsignedValueByConstructor) {
    unsigned int test_value{432};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.getType(), Type::UnsignedInteger);
}

TEST (AnyTypeTests, CreateFloatByConstructor) {
    float test_value{145.5};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.getType(), Type::Float);
}

TEST (AnyTypeTests, CreateDoubleByConstructor) {
    double test_value{242.2};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.getType(), Type::Double);
}

TEST (AnyTypeTests, CreateLongDoubleByConstructor) {
    long double test_value{234.2};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.getType(), Type::LongDouble);
}

TEST (AnyTypeTests, CreateBoolByConstructor) {
    bool test_value{true};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.getType(), Type::Bool);
}

TEST (AnyTypeTests, CreateCharByConstructor) {
    char test_value{94};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.getType(), Type::Char);
}

TEST (AnyTypeTests, EmptyConstructor) {
    AnyType anyType;

    ASSERT_EQ(anyType.getType(), Type::Empty);
}

TEST_F (TestFixtures, AssignNewValueInteger) {
    int test_value = 234;
    anyType = test_value;

    ASSERT_EQ(anyType.getType(), Type::Integer);
}

TEST_F (TestFixtures, AssignNewValueLongInt) {
    long int test_value{1242123};
    anyType = test_value;

    ASSERT_EQ(anyType.getType(), Type::LongInteger);
}

TEST_F (TestFixtures, AssignNewValueUnsignedInt) {
    unsigned int test_value{432};
    anyType = test_value;

    ASSERT_EQ(anyType.getType(), Type::UnsignedInteger);
}

TEST_F (TestFixtures, AssignNewValueFloat) {
    float test_value{145.5};
    anyType = test_value;

    ASSERT_EQ(anyType.getType(), Type::Float);
}

TEST_F (TestFixtures, AssignNewValueDouble) {
    double test_value{242.2};
    anyType = test_value;

    ASSERT_EQ(anyType.getType(), Type::Double);
}

TEST_F (TestFixtures, AssignNewValueLongDouble) {
    long double test_value{234.2};
    anyType = test_value;

    ASSERT_EQ(anyType.getType(), Type::LongDouble);
}

TEST_F (TestFixtures, AssignNewValueBool) {
    bool test_value{true};
    anyType = test_value;

    ASSERT_EQ(anyType.getType(), Type::Bool);
}

TEST_F (TestFixtures, AssignNewValueChar) {
    char test_value{94};
    anyType = test_value;

    ASSERT_EQ(anyType.getType(), Type::Char);
}

TEST_F (TestFixtures, CopyConstructor) {
    AnyType testValue{anyType};

    ASSERT_EQ(testValue.getType(), Type::Integer);
    ASSERT_EQ(anyType.getType(), Type::Integer);
}

TEST_F (TestFixtures, CopyAssinment) {
    AnyType testValue{'a'};
    testValue = anyType;

    ASSERT_EQ(testValue.getType(), Type::Integer);
    ASSERT_EQ(anyType.getType(), Type::Integer);
}

TEST_F (TestFixtures, SwapObjects) {
    AnyType testValue{'a'};

    swap(anyType, testValue);
    ASSERT_EQ(testValue.getType(), Type::Integer);
    ASSERT_EQ(anyType.getType(), Type::Char);
}

TEST (AnyTypeTests, GetInteger) {
    int test_value{123};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.ToInt(), test_value);
}

TEST (AnyTypeTests, GetIntegerException) {
    char test_value{'a'};
    AnyType anyType{test_value};

    ASSERT_THROW(anyType.ToInt(), std::bad_cast);
}

TEST (AnyTypeTests, GetLongInteger) {
    long int test_value{123};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.ToLongInt(), test_value);
}

TEST (AnyTypeTests, GetLongIntegerException) {
    char test_value{'a'};
    AnyType anyType{test_value};

    ASSERT_THROW(anyType.ToLongInt(), std::bad_cast);
}

TEST (AnyTypeTests, GetUnsignedInteger) {
    unsigned int test_value{123};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.ToUnsignedInt(), test_value);
}

TEST (AnyTypeTests, GetUnsignedIntegerException) {
    char test_value{'a'};
    AnyType anyType{test_value};

    ASSERT_THROW(anyType.ToUnsignedInt(), std::bad_cast);
}

TEST (AnyTypeTests, GetFloat) {
    float test_value{123.5};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.ToFloat(), test_value);
}

TEST (AnyTypeTests, GetFloatException) {
    char test_value{'a'};
    AnyType anyType{test_value};

    ASSERT_THROW(anyType.ToFloat(), std::bad_cast);
}

TEST (AnyTypeTests, GetDouble) {
    double test_value{123.5};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.ToDouble(), test_value);
}

TEST (AnyTypeTests, GetDoubleException) {
    char test_value{'a'};
    AnyType anyType{test_value};

    ASSERT_THROW(anyType.ToDouble(), std::bad_cast);
}

TEST (AnyTypeTests, GetLongDouble) {
    long double test_value{123.5};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.ToLongDouble(), test_value);
}

TEST (AnyTypeTests, GetLongDoubleException) {
    char test_value{'a'};
    AnyType anyType{test_value};

    ASSERT_THROW(anyType.ToLongDouble(), std::bad_cast);
}

TEST (AnyTypeTests, GetBool) {
    bool test_value{true};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.ToBool(), test_value);
}

TEST (AnyTypeTests, GetBoolException) {
    char test_value{'a'};
    AnyType anyType{test_value};

    ASSERT_THROW(anyType.ToBool(), std::bad_cast);
}

TEST (AnyTypeTests, GetChar) {
    char test_value{'a'};
    AnyType anyType{test_value};

    ASSERT_EQ(anyType.ToChar(), test_value);
}

TEST (AnyTypeTests, GetCharException) {
    bool test_value{true};
    AnyType anyType{test_value};

    ASSERT_THROW(anyType.ToChar(), std::bad_cast);
}

TEST (AnyTypeTests, DeleteObject) {
    AnyType* anyType = new AnyType{3};

    delete anyType;

    ASSERT_EQ(anyType->getType(), Type::Empty);
}

int main(int args, char** argv) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}
