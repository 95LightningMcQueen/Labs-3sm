#include "header.h"

Stack::Stack(const int32_t& size) : size(size), top(0) {
    if(size < 1) throw std::invalid_argument("error with zero");
    arr = new int32_t[size];
}

Stack::~Stack(){
    if(arr != nullptr){
        delete []arr;
        arr = nullptr;
    }
}

Stack::Stack(const Stack& other) : size(other.size), top(other.top) {
    arr = new int32_t[size];
    for(size_t i = 0; i < top; ++i){
        arr[i] = other.arr[i];
    }
}

Stack::Stack(Stack&& other) : size(std::move(other.size)), top(std::move(other.top)), arr(other.arr)
{
    other.arr = nullptr;
    other.top = 0;
}

Stack& Stack::operator=(Stack& other){
    if(this == &other) return *this;

    delete[] arr;

    const_cast<int32_t&>(size) = other.size;
    top = other.top;
    arr = new int32_t[size];

    for(size_t i = 0; i < top; ++i){
        arr[i] = other.arr[i];
    }

    return *this;
}

Stack& Stack::operator=(Stack&& other) {
    if(this == &other) return *this;

    delete[] arr;

    const_cast<int32_t&>(size) = other.size;
    top = other.top;
    arr = other.arr;

    other.arr = nullptr;
    other.top = 0;

    return *this;
}

void Stack::push(int32_t num){
    if(IsFull()) throw std::out_of_range("Stack is full");
    arr[++top] = num;
}

void Stack::pop(){
    if(IsEmpty()) throw std::invalid_argument("Stack is empty");
    --top;
}

int32_t Stack::peek(){
    if(IsEmpty()) throw std::invalid_argument("Stack is empty");
    return arr[top-1];
}

bool Stack::IsEmpty(){
    return top == 0;
}

bool Stack::IsFull(){
    return top == size;
}
