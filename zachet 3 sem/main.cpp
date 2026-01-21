#include "Litra.h"


int main()
{
    LitraPro book1(1, "War and Peace", Roman, 1800);
    LitraPro book2(2, "Mumu", Povest, 1900);
    book1.Print(std::cout);
    std::cout << '\n';
    book2.Print(std::cout);
    std::cout << '\n';
    if (book1 == book2)
    {
        std::cout << "Equal" << '\n';
    }
    else
    {
        std::cout << "Not equal" << '\n';
    }

    return 0;
}