#include <iostream>
#include <vector>
#include "AnyType.h"
#include "utils.h"

enum Options {
    Exit,
    AddNewElement,
    ChangeElement,
    OutputElement,
    Swap,
    GetType
};

int main() {
    bool condition{true};
    std::string choice{};
    int option{0};
    std::vector<AnyType> elements;

    while (condition) {
        std::cout << "1 - Add new element to a vector\n" \
                     "2 - Change a value\n" \
                     "3 - Output a value\n" \
                     "4 - Swap two values\n" \
                     "5 - Get a type of an element \n" \
                     "6 - Delete a value from an element\n" \
                     "0 - Exit\n";

        std::cout << "Please, enter your choice: ";
        getline(std::cin, choice);
        option = std::stoi(choice);

        switch (option) {
            case Options::AddNewElement: addNewElement(elements); break;
            case Options::ChangeElement: changeElement(elements); break;
            case Options::OutputElement: outputElement(elements); break;
            case Options::Swap: swapElements(elements); break;
            case Options::GetType: getType(elements); break;
            case Options::Exit: condition = false;
        }
    }
}
