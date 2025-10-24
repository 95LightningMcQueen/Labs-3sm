#include "complex.h"


int main()
{
    try
    {
        Complex a;
        Complex b(3.0);
        Complex c(1.0, -2.0);
        std::cout << "a = " << a << '\n';
        std::cout << "b = " << b << '\n';
        std::cout << "c = " << c << '\n';
        std::cout << "b + c = " << (b + c) << '\n';
        std::cout << "b - c = " << (b - c) << '\n';
        std::cout << "b * c = " << (b * c) << '\n';
        std::cout << "b / c = " << (b / c) << '\n';
        Complex t = c;
        t += Complex(2.0, 1.0);
        std::cout << "c += (2 + 1i) equal " << t << '\n';
        Complex u = c;
        u -= Complex(0.5, 0.5);
        std::cout << "c -= (0.5 + 0.5i) equal " << u << '\n';
        Complex v = b;
        v *= c;
        std::cout << "b *= c equal" << v << '\n';
        Complex w = b;
        try
        {
            w /= c;
            std::cout << "b /= c equal " << w << '\n';
        }
        catch (const std::exception& e)
        {
            std::cout << "Unexpected division error: " << e.what() << '\n';
        }
        std::cout << "-c = " << -c << '\n';
        std::cout << "conjugate(c) = " << !c << '\n';
        std::cout << "abs(c) = " << c.abs() << '\n';
        std::cout << "arg(c) = " << c.arg() << '\n';
        std::cout << "c == (1 - 2i)? " << (c == Complex(1.0, -2.0) ? "true" : "false") << '\n';
        try
        {
            Complex zero(0.0, 0.0);
            Complex bad = b / zero;
        }
        catch (const std::exception& e)
        {
            std::cout << "Expected error: " << e.what() << '\n';
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}