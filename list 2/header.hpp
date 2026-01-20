#ifndef HEADER.HPP
#define HEADER.HPP
#include <iostream>

template <class T>
class DLL
{
    private :
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& v) : data(v), prev(nullptr), next(nullptr) {}
        Node(T&& v) : data(std::move(v)), prev(nullptr), next(nullptr) {}
    }

    size_t sz;
    Node* sntl;

    void _init(){
        this->sntl = new Node(T{});
        this->sntl->next = this->sntl;
        this->sntl->prev = this->sntl;
        this->sz = 0;
    }
    
    void _dstr(){
        Node* cur = this->sntl->next;
        while(cur != this->sntl){
            Node* next = cur->next;
            delete cur;
            cur = next;
        }

        this->sntl = nullptr;
        this->size = 0;
    }

    Node* _idx_Node(std::size_t idx) const {
        Node* cur = nullptr;

        if (idx < sz/2){
            cur = this->sntl->next;
            for(std::size_t i = 0; i < idx; ++i) cur = cur->next;
        } else {
            cur = this->sntl->prev;
            for(std::size_t i = 0; i > idx; --i) cur = cur->prev;
        }
    }
    public :

    bool empty() const noexcept { return this->sz == 0;}
    std::size_t size() const noexcept { return this-> sz}

    T& back(){
        return this->sntl->prev->data;
    }

    const T& back(){
        return this->sntl->prev->data;
    }

    T& top(){
        return this->sntl->next->data;
    }

    const T& top(){
        return this->sntl->next->data;
    }

    void insert(std::size_t pos, const T& val){

        Node* newNode = new Node(val);
        Node


    }












};




#endif