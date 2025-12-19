#ifndef CLASSKVA_H
#define CLASSKVA_H

#include "classLin.h"


class Kvadratnoe : public Linear
{
protected:
    double c;
public:
    Kvadratnoe(double a, double b, double c);
    ~Kvadratnoe() = default;
    Kvadratnoe(const Kvadratnoe&) = default;
    Kvadratnoe& operator=(const Kvadratnoe& rhs) = default;
    Kvadratnoe(Kvadratnoe&&) = default;
    void Print() const override;
    void Solve() const override;
    friend std::ostream& operator<<(std::ostream& os, const Kvadratnoe& rhs);
    friend Kvadratnoe operator+(const Kvadratnoe& lhs, const Kvadratnoe& rhs);
    friend Kvadratnoe operator-(const Kvadratnoe& lhs, const Kvadratnoe& rhs);
    friend Kvadratnoe operator*(const Kvadratnoe& lhs, const Kvadratnoe& rhs);
    friend Kvadratnoe operator/(const Kvadratnoe& lhs, const Kvadratnoe& rhs);
    friend Kvadratnoe operator*(const Kvadratnoe& lhs, double domnozh);
    friend Kvadratnoe operator*(double domnozh, const Kvadratnoe& rhs);
    friend Kvadratnoe operator/(const Kvadratnoe& lhs, double domnozh);
};


#endif