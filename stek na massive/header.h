#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <stdexcept>


class Stack{
    private:
        int32_t top;
        const int32_t size;
        int32_t* arr;
    public:
        Stack(const int32_t& = 100);
        ~Stack();

        Stack(const Stack&);
        Stack(Stack&&);

        Stack& operator=(Stack&&);
        Stack& operator=(Stack&);

        void push(int32_t);
        void pop();

        int32_t peek();
        bool IsEmpty();
        bool IsFull();

};




#endif