#ifndef TASK2_ANYTYPE_H
#define TASK2_ANYTYPE_H

enum class Type {
    Empty,
    Integer,
    LongInteger,
    UnsignedInteger,
    Float,
    Double,
    LongDouble,
    Bool,
    Char
};

struct AnyType {
    AnyType(int value) : intValue{value}, type{Type::Integer} {};
    AnyType(long int value) : longValue{value}, type{Type::LongInteger} {};
    AnyType(unsigned int value) : uintValue{value}, type{Type::UnsignedInteger} {};
    AnyType(float value) : floatValue{value}, type{Type::Float} {};
    AnyType(double value) : doubleValue{value}, type{Type::Double} {};
    AnyType(long double value) : longDoubleValue{value}, type{Type::LongDouble} {};
    AnyType(bool value) : boolValue{value}, type{Type::Bool} {};
    AnyType(char value) : charValue{value}, type{Type::Char} {};
    AnyType() : longDoubleValue{0}, type{Type::Empty} {};
    AnyType(const AnyType&); // copy constructor

    void operator=(int value);
    void operator=(long int value);
    void operator=(unsigned int value);
    void operator=(float value);
    void operator=(double value);
    void operator=(long double value);
    void operator=(bool value);
    void operator=(char value);
    AnyType& operator=(const AnyType&) noexcept; // copy assignment

    Type getType() const;

    int ToInt() const;
    long int ToLongInt() const;
    unsigned int ToUnsignedInt() const;
    float ToFloat() const;
    double ToDouble() const;
    long double ToLongDouble() const;
    bool ToBool() const;
    char ToChar() const;

    void swap(AnyType&);

    ~AnyType();

private:
    union {
        int intValue;
        long int longValue;
        unsigned int uintValue;
        float floatValue;
        double doubleValue;
        long double longDoubleValue;
        bool boolValue;
        char charValue;
    };
    Type type{Type::Empty};
};

#endif //TASK2_ANYTYPE_H
