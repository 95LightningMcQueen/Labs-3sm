#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

class Array 
{
private:
    int32_t arraySize;
    int32_t* ptr;
    void fillArray();
public:
    Array();
    Array(int32_t);
    Array(const Array&);
    ~Array();
    void PrintArray();
};

#endif