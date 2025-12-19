#include "classKva.h"


Kvadratnoe::Kvadratnoe(double a, double b, double c) : Linear(a, b), c(c) {}

void Kvadratnoe::Print() const
{
    std::cout << "Kvadratnoe uravnenie: ";
    if (a < 0)
    {
        std::cout << "- " << -a << "x^2 ";
    }
    else
    {
        std::cout << a << "x^2 ";
    }
    if (b < 0)
    {
        std::cout << "- " << -b << "x ";
    }
    else
    {
        std::cout << "+ " << b << "x ";
    }
    if (c < 0)
    {
        std::cout << "- " << -c << ' ';
    }
    else
    {
        std::cout << "+ " << c << " ";
    }
    std::cout << "= 0";
}

void Kvadratnoe::Solve() const
{
    double D = b * b - 4.0 * a * c;
    if (D > 0.0)
    {
        double sqrtD = std::sqrt(D);
        double x1 = (-b + sqrtD) / (2.0 * a);
        double x2 = (-b - sqrtD) / (2.0 * a);
        std::cout << "\nSolutions: x1 = " << x1 << ", x2 = " << x2 << '\n';
    }
    else if (D == 0.0)
    {
        double x = -b / (2.0 * a);
        std::cout << "\nOne real solution: x = " << x << '\n';
    }
    else
    {
        std::cout << "\nNo real solutions (discr < 0)\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Kvadratnoe& rhs)
{
    os << '(' << rhs.a << ", " << rhs.b << ", " << rhs.c << ')';
    return os;
}

Kvadratnoe operator+(const Kvadratnoe& lhs, const Kvadratnoe& rhs)
{
    return Kvadratnoe(lhs.a + rhs.a, lhs.b + rhs.b, lhs.c + rhs.c);
}

Kvadratnoe operator-(const Kvadratnoe& lhs, const Kvadratnoe& rhs)
{
    return Kvadratnoe(lhs.a - rhs.a, lhs.b - rhs.b, lhs.c - rhs.c);
}

Kvadratnoe operator*(const Kvadratnoe& lhs, const Kvadratnoe& rhs)
{
    return Kvadratnoe(lhs.a * rhs.a, lhs.b * rhs.b, lhs.c * rhs.c);
}

Kvadratnoe operator/(const Kvadratnoe& lhs, const Kvadratnoe& rhs)
{
    if (rhs.a == 0.0 || rhs.b == 0.0 || rhs.c == 0.0)
    {
        throw std::invalid_argument("Division by zero");
    }
    return Kvadratnoe(lhs.a / rhs.a, lhs.b / rhs.b, lhs.c / rhs.c);
}

Kvadratnoe operator*(const Kvadratnoe& lhs, double domnozh)
{
    return Kvadratnoe(lhs.a * domnozh, lhs.b * domnozh, lhs.c * domnozh);
}

Kvadratnoe operator*(double domnozh, const Kvadratnoe& rhs)
{
    return rhs * domnozh;
}

Kvadratnoe operator/(const Kvadratnoe& lhs, double domnozh)
{
    if (domnozh == 0.0)
    {
        throw std::invalid_argument("Division by zero");
    }
    return Kvadratnoe(lhs.a / domnozh, lhs.b / domnozh, lhs.c / domnozh);
}