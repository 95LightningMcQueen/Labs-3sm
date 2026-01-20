#include "list.h"

int main()
{
    try
    {
        setlocale(LC_ALL, ".1251");
        List L;
        L.ListPrint();
        L.ForEach(Print);
        L.InsertFirst(10);
        L.InsertFirst(20);
        L.InsertFirst(30);
        L.ListPrint();
        List M = L;
        cout << "список М" << '\n';
        M.ListPrint();
        M.ForEach(Print);
        int a = L.Top();
        cout << "Элемент в начале списка=";
        cout << a << endl;
        if (L.DeleteFirst())
        {
            cout << "после удаления" << '\n';
            L.ListPrint();
        }
        else
            cout << "список пуст" << '\n';
        if (L.DeleteFirst())
        {
            cout << "после удаления" << '\n';
            L.ListPrint();
        }
        else
            cout << "список пуст" << '\n';
        L.InsertFirst(40);
        L.ListPrint();
        if (L.DeleteFirst())
        {
            cout << "после удаления" << '\n';
            L.ListPrint();
        }
        else {
            cout << "список пуст" << '\n';
        }

        L.InsertSorted(15);
        L.ListPrint();
        L.InsertSorted(16);
        L.ListPrint();
        L.InsertSorted(150);
        L.ListPrint();
        L.InsertSorted(1200);
        L.ListPrint();
        L.InsertSorted(1300);
        L.ListPrint();
        L.InsertSorted(11000);
        L.ListPrint();
    }
    catch (const char* msg)
    {
        cerr << "Ошибка: " << msg << '\n';
    }
    return 0;
}
