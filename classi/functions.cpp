#include "functions.h"

Array::Array() 
{
    this->arraySize = 5;
    this->ptr = new int32_t[arraySize];
    fillArray();
}

Array::Array(int32_t size) 
{
    this->arraySize = size;
    this->ptr = new int32_t[arraySize];
    fillArray();
}

void Array::fillArray() 
{
    for (size_t i{}; i < arraySize; ++i) 
    {
        ptr[i] = 0;
    }
}

Array::Array(const Array& init) 
{
    this->arraySize = init.arraySize;
    this->ptr = new int32_t[arraySize];
    for (size_t i{}; i < arraySize; ++i) 
    {
        this->ptr[i] = init.ptr[i];
    }
}

void Array::PrintArray()
{
    for (size_t i{}; i < arraySize; ++i)
    {
        std::cout << ptr[i] << ' ';
    }
    std::cout << '\n';
}

Array::~Array() 
{
    delete[] ptr;
}