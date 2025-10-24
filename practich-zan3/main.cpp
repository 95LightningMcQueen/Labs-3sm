#include "List.h"


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
        std::cout << "список М" << '\n';
        M.ListPrint();
        M.ForEach(Print);
        int a = L.Top();
        std::cout << "Элемент в начале списка=";
        std::cout << a << '\n';
        if (L.DeleteFirst())
        {
            std::cout << "после удаления" << '\n';
            L.ListPrint();
        }
        else
            std:: cout << "список пуст" << '\n';
        if (L.DeleteFirst())
        {
            std::cout << "после удаления" << '\n';
            L.ListPrint();
        }
        else
            std::cout << "список пуст" << '\n';
        L.InsertFirst(40);
        L.ListPrint();
        if (L.DeleteFirst());
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << '\n';
        }
        return 0;
    }

