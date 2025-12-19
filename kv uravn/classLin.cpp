#include "classLin.h"


Linear::Linear(double a, double b) : a(a), b(b)
{
    if (a == 0.0)
    {
        throw std::invalid_argument("Linear: coefficient 'a' must not be zero");
    }
}

void Linear::Print() const
{
    std::cout << "Linear: " << a << "x ";
    if (b < 0)
    {
        std::cout << "- " << -b;
    }
    else
    {
        std::cout << "+ " << b;
    }
    std::cout << " = 0";
}

void Linear::Solve() const
{
    double x = -b / a;
    std::cout << "\nSolution: x = " << x << '\n';
}

std::ostream& operator<<(std::ostream& os, const Linear& rhs)
{
    os << '(' << rhs.a << ", " << rhs.b << ')';
    return os;
}

Linear operator+(const Linear& lhs, const Linear& rhs)
{
    return Linear(lhs.a + rhs.a, lhs.b + rhs.b);
}

Linear operator-(const Linear& lhs, const Linear& rhs)
{
    return Linear(lhs.a - rhs.a, lhs.b - rhs.b);
}

Linear operator*(const Linear& lhs, const Linear& rhs)
{
    return Linear(lhs.a * rhs.a, lhs.b * rhs.b);
}

Linear operator/(const Linear& lhs, const Linear& rhs)
{
    if (rhs.a == 0.0 || rhs.b == 0.0)
    {
        throw std::invalid_argument("Division by zero");
    }
    return Linear(lhs.a / rhs.a, lhs.b / rhs.b);
}

Linear operator*(const Linear& lhs, double domnozh)
{
    return Linear(lhs.a * domnozh, lhs.b * domnozh);
}

Linear operator*(double domnozh, const Linear& rhs)
{
    return rhs * domnozh;
}

Linear operator/(const Linear& lhs, double domnozh)
{
    if (domnozh == 0.0)
    {
        throw std::invalid_argument("Division by zero");
    }
    return Linear(lhs.a / domnozh, lhs.b / domnozh);
}