#ifndef TASK2_UTILS_H
#define TASK2_UTILS_H
#include <vector>
#include "AnyType.h"

void swap(AnyType&, AnyType&);

// Create a new element of type "AnyType" and then adds it to the vector
void addNewElement(std::vector<AnyType>& elements);

// Change an element which exists in vector
void changeElement(std::vector<AnyType>& elements);

// Output an element of a particular type
void outputElement(std::vector<AnyType>& elements);

// Swap two values which exists in a vector
void swapElements(std::vector<AnyType>& elements);

// Output a type of an element in a vector
void getType(std::vector<AnyType>& elements);

#endif //TASK2_UTILS_H
