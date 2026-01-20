#include "list.h"

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
    return First->Info;
}

void List::Clone(const List& L)
{
    ListItem* p = L.First;
    ListItem* r = NULL;

    while (p != NULL)
    {
        ListItem* q = new ListItem;
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
    ListItem* p = First;
    while (p != NULL)
    {
        ListItem* q = p->Next;
        delete p;
        p = q;
    }
    First = NULL;
}

List::List() : First(NULL) {}

List::List(const List& L)
{
    Clone(L);
}

const List& List::operator=(const List& L)
{
    if (&L == this)
        return *this;
    Erase();
    Clone(L);
    return *this;
}

void List::ListPrint() const
{
    if (First == NULL)
    {
        cout << "список пуст" << endl;
        return;
    }

    cout << "содержимое списка" << endl;
    for (ListItem* P = First; P != NULL; P = P->Next)
        cout << P->Info << endl;
}

void Print(int x)
{
    cout << x << ' ';
}

void List::ForEach(void Fun(int)) const
{
    if (First == NULL)
    {
        cout << "список пуст" << '\n';
        return;
    }

    cout << "содержимое списка" << '\n';
    for (ListItem* P = First; P != NULL; P = P->Next)
        Fun(P->Info);
}

void List::ForEach(void Fun(int&))
{
    for (ListItem* P = First; P != NULL; P = P->Next)
        Fun(P->Info);
}

List::~List()
{
    Erase();
}

void PrintSquare(int x)
{
    cout << x * x << " ";
}

void Double(int& x)
{
    x *= 2;
}

void Increment(int& x)
{
    ++x;
}

void MakeNegative(int& x)
{
    x = -x;
}


void List::InsertSorted(const int& value)
{
    ListItem* newNode = new ListItem;
    newNode->Info = value;
    newNode->Next = NULL;
 
    if (First == NULL || value < First->Info)
    {
        newNode->Next = First;
        First = newNode;
        return; 
    }

    ListItem* current = First;

    while (current->Next != NULL && current->Next->Info < value)
    {
        current = current->Next;
    }
    newNode->Next = current->Next;
    current->Next = newNode;
}
