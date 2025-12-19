#ifndef CLASSLIN_H
#define CLASSLIN_H

#include <iostream>
#include <cmath>
#include <stdexcept>


class Linear
{
protected:
    double a;
    double b;
public:
    Linear(double a, double b = 0.0);
    ~Linear() = default;
    Linear(const Linear&) = default;
    Linear& operator=(const Linear& rhs) = default;
    Linear(Linear&&) = default;
    virtual void Print() const;
    virtual void Solve() const;
    friend std::ostream& operator<<(std::ostream& os, const Linear& rhs);
    friend Linear operator+(const Linear& lhs, const Linear& rhs);
    friend Linear operator-(const Linear& lhs, const Linear& rhs);
    friend Linear operator*(const Linear& lhs, const Linear& rhs);
    friend Linear operator/(const Linear& lhs, const Linear& rhs);
    friend Linear operator*(const Linear& lhs, double scalar);
    friend Linear operator*(double domnozh, const Linear& rhs);
    friend Linear operator/(const Linear& lhs, double scalar);
};


#endif