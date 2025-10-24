#ifndef HEADER_H
#define HEADER_H

#include <iostream>

class List
{
protected:
    struct ListItem
    {
        int Info;
        ListItem* Next;
    };
    ListItem* First;
public:
    void InsertFirst(const int&);
    bool DeleteFirst();
    const int Top() const;
    void ListPrint() const;
    void ForEach(void(int)) const;
    void ForEach(void(int&));
    List();
    List(const List&);
    const List& operator = (const List&);
    virtual ~List();
    void Erase();
protected:
    void Clone(const List&);
};

#endif