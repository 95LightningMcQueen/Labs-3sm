#include "List.h"

void List::InsertFirst(const int& Alnfo)
{
    ListItem* P = new ListItem;
    P->Info = Alnfo;
    P->Next = First;
    First = P;
}

bool List::DeleteFirst()
{
    if (First == NULL)
        return false;
    ListItem* P = First;
    First = First->Next;
    delete P;
    return true;
}

const int List::Top() const
{
    if (First == NULL)
        throw "Список пустой";
    int x = First->Info;
    return x;
}

void List::Clone(const List& L)
{
    ListItem* p, * q, * r;
    r = NULL;
    p = L.First;
    while (p != NULL)
    {
        q = new ListItem;
        q->Info = p->Info;
        q->Next = NULL;
        if (r == NULL)
            First = q;
        else
            r->Next = q;
        r = q;
        p = p->Next;
    }
}

void List::Erase()
{
    ListItem* p, * q;
    p = First;
    while (p != NULL)
    {
        q = p->Next;
        delete p;
        p = q;
    }
    First = NULL;
}

List::List(const List& L)
{
    Clone(L);
}

const List& List::operator = (const List& L)
{
    if (&L == this)
        return *this;
    Erase();
    Clone(L);
    return *this;
}

void List::ListPrint() const
{
    ListItem* P = First;
    if (P == NULL)
        std::cout << "список пуст" << '\n';
    if (P != NULL)
    {
        std::cout << "содержимое списка" << '\n';
        while (P != NULL)
        {
            std::cout << P->Info << '\n';
            P = P->Next;
        }
    }
}

void Print(int x)
{
    std::cout << x << '\n';
}

void List::ForEach(void Fun(int)) const
{
    ListItem* P = First;
    if (P == NULL)
        std::cout << "список пуст" << '\n';
    if (P != NULL)
    {
        std::cout << "содержимое списка" << '\n';
        while (P != NULL)
        {
            Fun(P->Info);
            P = P->Next;
        }
    }
}

List::~List()
{
    Erase();
}

void ForEach(void(int&))
{}
