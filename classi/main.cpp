#include "functions.h"


int main() 
{
    Array a;
    Array b(5);
    Array c(a);
    Array d{ a };
    Array g = d;

    std::cout << "a: "; a.PrintArray();
    std::cout << "b: "; b.PrintArray();
    std::cout << "c: "; c.PrintArray();
    std::cout << "d: "; d.PrintArray();
    std::cout << "g: "; g.PrintArray();

    return 0;
}