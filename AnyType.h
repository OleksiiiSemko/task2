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
    //Constructors
    explicit AnyType(int value) : intValue{value}, type{Type::Integer} {};
    explicit AnyType(long int value) : longValue{value}, type{Type::LongInteger} {};
    explicit AnyType(unsigned int value) : uintValue{value}, type{Type::UnsignedInteger} {};
    explicit AnyType(float value) : floatValue{value}, type{Type::Float} {};
    explicit AnyType(double value) : doubleValue{value}, type{Type::Double} {};
    explicit AnyType(long double value) : longDoubleValue{value}, type{Type::LongDouble} {};
    explicit AnyType(bool value) : boolValue{value}, type{Type::Bool} {};
    explicit AnyType(char value) : charValue{value}, type{Type::Char} {};
    explicit AnyType() : longDoubleValue{0}, type{Type::Empty} {};
    AnyType(const AnyType&); // copy constructor

    //Assignment operators
    AnyType& operator=(int value);
    AnyType& operator=(long int value);
    AnyType& operator=(unsigned int value);
    AnyType& operator=(float value);
    AnyType& operator=(double value);
    AnyType& operator=(long double value);
    AnyType& operator=(bool value);
    AnyType& operator=(char value);
    AnyType& operator=(const AnyType&) noexcept; // copy assignment

    Type getType() const;

    // If value is not integer, exception will be thrown
    int ToInt() const;
    // If value is not long integer, exception will be thrown
    long int ToLongInt() const;
    // If value is not unsigned integer, exception will be thrown
    unsigned int ToUnsignedInt() const;
    // If value is not float, exception will be thrown
    float ToFloat() const;
    // If value is not double, exception will be thrown
    double ToDouble() const;
    // If value is not long double, exception will be thrown
    long double ToLongDouble() const;
    // If value is not bool, exception will be thrown
    bool ToBool() const;
    // If value is not char, exception will be thrown
    char ToChar() const;

    //Swap two values of type "AnyType"
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
    void assignByType(const AnyType& anyType);
    //Checks that type corresponds to the object type, in the opposite way throw exception
    void checkType(Type type_) const;
    Type type{Type::Empty};
};

#endif //TASK2_ANYTYPE_H
