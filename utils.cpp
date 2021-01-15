#include <iostream>
#include <vector>
#include "AnyType.h"

void waiter();
Type chooseType();
void assignValue(AnyType&, Type, std::string);
std::string getValue();
int getIndex(int size);

void swap(AnyType& a, AnyType& b) {
    a.swap(b);
}

void addNewElement(std::vector<AnyType>& elements) {
    try {
        Type type = chooseType();
        std::string value = getValue();
        AnyType anyType;
        assignValue(anyType, type, value);
        elements.push_back(anyType);
    }
    catch (std::bad_cast& err) {
        std::cerr << err.what();
    }
    waiter();
}

void changeElement(std::vector<AnyType>& elements) {
    try {
        int index = getIndex(elements.size());

        Type type = chooseType();
        std::string value = getValue();
        assignValue(elements[index], type, value);
    }
    catch(std::bad_cast& err) {
        std::cerr << err.what() << std::endl;
    }
    catch(std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    waiter();
}

void outputElement(std::vector<AnyType>& elements) {
    try {
        int index = getIndex(elements.size());
        Type type = chooseType();

        switch (type) {
            case Type::Integer:
                std::cout << elements[index].ToInt() << std:: endl;
                break;
            case Type::LongInteger:
                std::cout << elements[index].ToLongInt() << std::endl;
                break;
            case Type::UnsignedInteger:
                std::cout << elements[index].ToUnsignedInt() << std::endl;
                break;
            case Type::Float:
                std::cout << elements[index].ToFloat() << std::endl;
                break;
            case Type::Double:
                std::cout << elements[index].ToDouble() << std::endl;
                break;
            case Type::LongDouble:
                std::cout << elements[index].ToLongDouble() << std::endl;
                break;
            case Type::Bool:
                std::cout << elements[index].ToBool() << std::endl;
                break;
            case Type::Char:
                std::cout << elements[index].ToChar() << std::endl;
                break;
        }
    }
    catch (std::bad_cast& err) {
        std::cerr << "Wrong type has been chosen\n";
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    waiter();
}

void swapElements(std::vector<AnyType>& elements) {
    try {
        int index1 = getIndex(elements.size());
        int index2 = getIndex(elements.size());

        swap(elements[index1], elements[index2]);
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    waiter();
}

void getType(std::vector<AnyType>& elements) {
    try {
        int index = getIndex(elements.size());

        switch (elements[index].getType()) {
            case Type::Integer:
                std::cout << "Integer\n";
                break;
            case Type::LongInteger:
                std::cout << "Long Integer\n";
                break;
            case Type::UnsignedInteger:
                std::cout << "Unsigned integer\n";
                break;
            case Type::Float:
                std::cout << "Float\n";
                break;
            case Type::Double:
                std::cout << "Double\n";
                break;
            case Type::LongDouble:
                std::cout << "Long Double\n";
                break;
            case Type::Bool:
                std::cout << "Bool\n";
                break;
            case Type::Char:
                std::cout << "Char\n";
                break;
            case Type::Empty:
                std::cout << "The element is empty\n";
                break;
        }
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    waiter();
}

Type chooseType() {
    std::cout << "1 - Integer\n" \
                 "2 - Long Integer\n" \
                 "3 - Unsigned integer\n" \
                 "4 - Float\n" \
                 "5 - Double\n" \
                 "6 - Long Double\n" \
                 "7 - Bool\n" \
                 "8 - Char\n" \
                 "Please choose a type of value: ";

    std::string choice;
    getline(std::cin, choice);

    return static_cast<Type>(std::stoi(choice));
}

std::string getValue() {
    std::cout << "Please enter a value: ";
    std::string value{};
    getline(std::cin, value);

    return value;
}

void assignValue(AnyType& anyType, Type type, std::string value) {
    switch (type) {
        case Type::Integer:
            anyType = stoi(value);
            break;
        case Type::LongInteger:
            anyType = stol(value);
            break;
        case Type::UnsignedInteger:
            anyType = static_cast<unsigned int>(stoi(value));
            break;
        case Type::Float:
            anyType = stof(value);
            break;
        case Type::Double:
            anyType = stod(value);
            break;
        case Type::LongDouble:
            anyType = stold(value);
            break;
        case Type::Bool:
            anyType = static_cast<bool>(stoi(value));
            break;
        case Type::Char:
            anyType = static_cast<char>(stoi(value));
            break;
    }
}

int getIndex(int size) {
    std::cout << "There are " << size << " elements in vector\n";
    std::cout << "Please, enter an index of an element: ";
    std::string stringIndex;
    getline(std::cin, stringIndex);
    int index = stoi(stringIndex);

    if (index > size - 1) {
        throw std::out_of_range("Out of elements range");
    }

    return index;
}

void waiter() {
    std::cout << "Press Enter to continue\n";
    getchar();
}
