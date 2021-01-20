#include <typeinfo>
#include "AnyType.h"

AnyType& AnyType::operator=(int value) {
    intValue = value;
    type = Type::Integer;

    return *this;
}

AnyType& AnyType::operator=(long int value) {
    longValue = value;
    type = Type::LongInteger;

    return *this;
}

AnyType& AnyType::operator=(unsigned int value) {
    uintValue = value;
    type = Type::UnsignedInteger;

    return *this;
}

AnyType& AnyType::operator=(float value) {
    floatValue = value;
    type = Type::Float;

    return *this;
}

AnyType& AnyType::operator=(double value) {
    doubleValue = value;
    type = Type::Double;

    return *this;
}

AnyType& AnyType::operator=(long double value) {
    longDoubleValue = value;
    type = Type::LongDouble;

    return *this;
}

AnyType& AnyType::operator=(bool value) {
    boolValue = value;
    type = Type::Bool;

    return *this;
}

AnyType& AnyType::operator=(char value) {
    charValue = value;
    type = Type::Char;

    return *this;
}

AnyType::AnyType(const AnyType& a) : type{a.type} {
    assignByType(a);
}

AnyType& AnyType::operator=(const AnyType& a) noexcept {
    assignByType(a);
    type = a.type;

    return *this;
}

Type AnyType::getType() const {
    return type;
}

int AnyType::ToInt() const {
    checkType(Type::Integer);
    return intValue;
}

long int AnyType::ToLongInt() const {
    checkType(Type::LongInteger);
    return longValue;
}

unsigned int AnyType::ToUnsignedInt() const {
    checkType(Type::UnsignedInteger);
    return uintValue;
}

float AnyType::ToFloat() const {
    checkType(Type::Float);
    return floatValue;
}

double  AnyType::ToDouble() const {
    checkType(Type::Double);
    return doubleValue;
}

long double AnyType::ToLongDouble() const {
    checkType(Type::LongDouble);
    return longDoubleValue;
}

bool AnyType::ToBool() const {
    checkType(Type::Bool);
    return boolValue;
}

char AnyType::ToChar() const {
    checkType(Type::Char);
    return charValue;
}

void AnyType::swap(AnyType& a) {
    const AnyType tmp = *this;
    *this = a;
    a = tmp;
}

AnyType::~AnyType() {
    longDoubleValue = 0;
    type = Type::Empty;
}

void AnyType::assignByType(const AnyType &a) {
    switch (a.type) {
        case Type::Integer: *this = a.intValue; break;
        case Type::LongInteger: *this = a.longValue; break;
        case Type::UnsignedInteger: *this = a.uintValue; break;
        case Type::Float: *this = a.floatValue; break;
        case Type::Double: *this = a.doubleValue; break;
        case Type::LongDouble: *this = a.longDoubleValue; break;
        case Type::Bool: *this = a.boolValue; break;
        case Type::Char: *this = a.charValue; break;
        case Type::Empty: *this = a;
    }
}

void AnyType::checkType(Type type_) const {
    if(type != type_) {
        throw std::bad_cast();
    }
}