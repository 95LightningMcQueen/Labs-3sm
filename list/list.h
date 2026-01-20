#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

void Print(int x);

class List
{
private:
    struct ListItem
    {
        int Info;
        ListItem* Next;
    };
    ListItem* First;
public:
    List();
    List(const List&);
    ~List();
    const List& operator=(const List&);
    void InsertFirst(const int&);
    bool DeleteFirst();
    const int Top() const;
    void ListPrint() const;
    void ForEach(void Fun(int)) const;
    void ForEach(void Fun(int&));
    void Erase();
    List* _idx_list(size_t idx);
    void InsertSorted(const int& value);
private:
    void Clone(const List&);
};

void Print(int);
void PrintSquare(int);


void Double(int&);
void Increment(int&);
void MakeNegative(int&);

#endif
