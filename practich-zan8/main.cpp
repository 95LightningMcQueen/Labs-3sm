#include "class2D.h"
#include "class3D.h"


int main()
{
    Point2D a(1, 2);
    Point2D b(3, 4);
    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    Point2D c = a + b;
    Point2D d = b - a;
    Point2D e = a * b;
    std::cout << "c = a + b equal " << c << '\n';
    std::cout << "d = b - a equal " << d << '\n';
    std::cout << "e = a * b equal " << e << '\n';
    a += b;
    std::cout << "a += b equal = " << a << '\n';
    b -= a;
    std::cout << "b -= a equal " << b << '\n';
    c *= a;
    std::cout << "c *= a equal " << c << '\n';

    Point3D z(1, 2, 3);
    Point3D x(4, 5, 6);
    Point3D v = z + x;
    v *= Point3D(1, 2, 3);
    std::cout << "\nz: " << z << '\n';
    std::cout << "x: " << x << '\n';
    std::cout << "v: " << v << '\n';
    
    
    return 0;
}