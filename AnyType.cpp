#include <typeinfo>
#include "AnyType.h"

void AnyType::operator=(int value) {
    intValue = value;
    type = Type::Integer;
}

void AnyType::operator=(long int value) {
    longValue = value;
    type = Type::LongInteger;
}

void AnyType::operator=(unsigned int value) {
    uintValue = value;
    type = Type::UnsignedInteger;
}

void AnyType::operator=(float value) {
    floatValue = value;
    type = Type::Float;
}

void AnyType::operator=(double value) {
    doubleValue = value;
    type = Type::Double;
}

void AnyType::operator=(long double value) {
    longDoubleValue = value;
    type = Type::LongDouble;
}

void AnyType::operator=(bool value) {
    boolValue = value;
    type = Type::Bool;
}

void AnyType::operator=(char value) {
    charValue = value;
    type = Type::Char;
}

AnyType::AnyType(const AnyType& a) : type{a.type} {
    switch (type) {
        case Type::Integer: *this = a.intValue; break;
        case Type::LongInteger: *this = a.longValue; break;
        case Type::UnsignedInteger: *this = a.uintValue; break;
        case Type::Float: *this = a.floatValue; break;
        case Type::Double: *this = a.doubleValue; break;
        case Type::LongDouble: *this = a.longDoubleValue; break;
        case Type::Bool: *this = a.boolValue; break;
        case Type::Char: *this = a.charValue; break;
    }
}

AnyType& AnyType::operator=(const AnyType& a) noexcept {
    switch (a.type) {
        case Type::Integer: *this = a.intValue; break;
        case Type::LongInteger: *this = a.longValue; break;
        case Type::UnsignedInteger: *this = a.uintValue; break;
        case Type::Float: *this = a.floatValue; break;
        case Type::Double: *this = a.doubleValue; break;
        case Type::LongDouble: *this = a.longDoubleValue; break;
        case Type::Bool: *this = a.boolValue; break;
        case Type::Char: *this = a.charValue; break;
    }
    type = a.type;
}

Type AnyType::getType() const {
    return type;
}

int AnyType::ToInt() const {
    if (type == Type::Integer) {
        return intValue;
    }
    else {
        throw std::bad_cast();
    }
}

long int AnyType::ToLongInt() const {
    if (type == Type::LongInteger) {
        return longValue;
    }
    else {
        throw std::bad_cast();
    }
}

unsigned int AnyType::ToUnsignedInt() const {
    if (type == Type::UnsignedInteger) {
        return uintValue;
    }
    else {
        throw std::bad_cast();
    }
}

float AnyType::ToFloat() const {
    if (type == Type::Float) {
        return floatValue;
    }
    else {
        throw std::bad_cast();
    }
}

double  AnyType::ToDouble() const {
    if (type == Type::Double) {
        return doubleValue;
    }
    else {
        throw std::bad_cast();
    }
}

long double AnyType::ToLongDouble() const {
    if (type == Type::LongDouble) {
        return longDoubleValue;
    }
    else {
        throw std::bad_cast();
    }
}

bool AnyType::ToBool() const {
    if (type == Type::Bool) {
        return boolValue;
    }
    else {
        throw std::bad_cast();
    }
}

char AnyType::ToChar() const {
    if (type == Type::Char) {
        return charValue;
    }
    else {
        throw std::bad_cast();
    }
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
