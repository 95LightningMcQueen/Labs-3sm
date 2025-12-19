#ifndef DLLIST_HPP
#define DLLIST_HPP

#include <iostream>


template<typename T>
class DLList 
{
    struct Node 
    {
        T data;
        Node* prev;
        Node* next;

        Node(const T& v) : data(v), prev(nullptr), next(nullptr) {}
    };
    Node* sntl;
    std::size_t sz;

    void _init() noexcept 
    {
        this->sntl = new Node(T{});
        this->sntl->next = this->sntl;
        this->sntl->prev = this->sntl;
        this->sz = 0;
    }

    void _dstr() noexcept 
    {
        Node* tmp = this->sntl->next;
        Node* cur{ nullptr };
        while (tmp != this->sntl) 
        {
            cur = tmp->next;
            delete tmp;
        }
        this->sz = 0;
        delete this->sntl;
    }

public:
    DLList() 
    {
        this->_init();
    }
    T front() 
    {
        return(this->sntl->next->data);
    }

    T back() 
    {
        return (this->sntl->prev->data);
    }

    const T& front() const 
    {
        return(this->sntl->next->data);
    }

    const T& back() const 
    {
        return (this->sntl->prev->data);
    }

    void insert(size_t pos, T& val) 
    {
        if (pos > this->sz) throw std::out_of_range("insert position out of range");
        Node* newNode = new Node(val);
        if (pos == this->sz) 
        {
            Node* posNode = this->sntl;
        }
        else 
        {
            Node* posNode = this->_idx_node(pos);
        }
        Node* prevNode = posNode->prev;
        prevNode->next = newNode;
        posNode->prev = newNode;
        newNode->next = posNode;
        newNode->prev = prevNode;
        ++(this->sz);
    }
    void erase(size_t pos) 
    {
        if (pos >= this->sz) throw std::out_of_range("erase position out of range");
        Node* eraseNode = this->_idx_node(pos);
        Node* nextNode = eraseNode->next;
        Node* prevNode = eraseNode->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
        delete eraseNode;
        --(this->sz);
    }


    ~DLList() 
    {
        this->_dstr();
    }

};
#endif