#ifndef STACK_LIST_H
#define STACK_LIST_H
#include <iostream>
#include <stdexcept>

template<typename T>
class StackList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    size_t count;

public:
    StackList();
    ~StackList();

    StackList(const StackList&);
    StackList(StackList&&);

    StackList& operator=(const StackList&);
    StackList& operator=(StackList&&);

    void push(const T&);
    void pop();

    T peek() const;
    bool IsEmpty() const;
    size_t size() const;
    void clear();
};

template<typename T>
StackList<T>::StackList() : head(nullptr), count(0) {}

template<typename T>
StackList<T>::~StackList() {
    clear();
}

template<typename T>
StackList<T>::StackList(const StackList& other) : head(nullptr), count(0) {
    if(other.head == nullptr) return;

    Node* otherCurrent = other.head;
    Node* prev = nullptr;

    while(otherCurrent != nullptr) {
        Node* newNode = new Node(otherCurrent->data);

        if(prev == nullptr) {
            head = newNode;
        } else {
            prev->next = newNode;
        }

        prev = newNode;
        otherCurrent = otherCurrent->next;
        ++count;
    }
}

template<typename T>
StackList<T>::StackList(StackList&& other) : head(other.head), count(other.count) {
    other.head = nullptr;
    other.count = 0;
}

template<typename T>
StackList<T>& StackList<T>::operator=(const StackList& other) {
    if(this == &other) return *this;

    clear();

    if(other.head == nullptr) return *this;

    Node* otherCurrent = other.head;
    Node* prev = nullptr;

    while(otherCurrent != nullptr) {
        Node* newNode = new Node(otherCurrent->data);

        if(prev == nullptr) {
            head = newNode;
        } else {
            prev->next = newNode;
        }

        prev = newNode;
        otherCurrent = otherCurrent->next;
        ++count;
    }

    return *this;
}

template<typename T>
StackList<T>& StackList<T>::operator=(StackList&& other) {
    if(this == &other) return *this;

    clear();

    head = other.head;
    count = other.count;

    other.head = nullptr;
    other.count = 0;

    return *this;
}

template<typename T>
void StackList<T>::push(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    ++count;
}

template<typename T>
void StackList<T>::pop() {
    if(IsEmpty()) throw std::invalid_argument("Stack is empty");

    Node* temp = head;
    head = head->next;
    delete temp;
    --count;
}

template<typename T>
T StackList<T>::peek() const {
    if(IsEmpty()) throw std::invalid_argument("Stack is empty");
    return head->data;
}

template<typename T>
bool StackList<T>::IsEmpty() const {
    return head == nullptr;
}

template<typename T>
size_t StackList<T>::size() const {
    return count;
}

template<typename T>
void StackList<T>::clear() {
    while(head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    count = 0;
}

#endif
