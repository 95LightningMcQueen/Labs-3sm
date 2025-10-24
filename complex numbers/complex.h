#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <stdexcept>


class Complex
{
private:
    double real;
    double imaginary;
public:
    /*Complex();
    Complex(double);*/
    Complex(double = 0, double = 0);
    ~Complex();
    double getReal() const;
    double getImag() const;
    double abs() const;
    double arg() const;
    void setReal(double r);
    void setImag(double i);
    Complex operator!() const;
    Complex operator-() const;
    Complex& operator=(const Complex& rhs);
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);
    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend Complex operator/(const Complex& a, const Complex& b);
    friend bool operator==(const Complex& a, const Complex& b);
    friend bool operator!=(const Complex& a, const Complex& b);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};


Complex::Complex()
{
    this->real = 0.0;
    this->imaginary = 0.0;
}

Complex::Complex(double d)
{
    this->real = d;
    this->imaginary = 0.0;
}

Complex::Complex(double re, double im)
{
    this->real = re;
    this->imaginary = im;
}

Complex::~Complex()
{
}

double Complex::getReal() const
{
    return this->real;
}

double Complex::getImag() const
{
    return this->imaginary;
}

double Complex::abs() const
{
    return std::hypot(this->real, this->imaginary);
}

double Complex::arg() const
{
    return std::atan2(this->real, this->imaginary);
}

void Complex::setReal(double r)
{
    this->real = r;
}

void Complex::setImag(double i)
{
    this->imaginary = i;
}

Complex Complex::operator-() const
{
    return Complex(-this->real, -this->imaginary);
}

Complex Complex::operator!() const
{
    return Complex(this->real, -this->imaginary);
}

Complex operator+(const Complex& a, const Complex& b)
{
    return Complex(a.real + b.real, a.imaginary + b.imaginary);
}

Complex operator-(const Complex& a, const Complex& b)
{
    return Complex(a.real - b.real, a.imaginary - b.imaginary);
}

Complex operator*(const Complex& a, const Complex& b)
{
    return Complex(a.real * b.real - a.imaginary * b.imaginary, a.real * b.imaginary + a.imaginary * b.real);
}

Complex operator/(const Complex& a, const Complex& b)
{
    double denom = b.real * b.real + b.imaginary * b.imaginary;
    if (denom == 0.0)
    {
        throw std::runtime_error("Division by zero");
    }
    return Complex((a.real * b.real + a.imaginary * b.imaginary) / denom, (a.imaginary * b.real - a.real * b.imaginary) / denom);
}

Complex& Complex::operator+=(const Complex& other)
{
    this->real += other.real;
    this->imaginary += other.imaginary;
    return *this;
}

Complex& Complex::operator-=(const Complex& o)
{
    this->real -= o.real;
    this->imaginary -= o.imaginary;
    return *this;
}

Complex& Complex::operator*=(const Complex& o)
{
    double nr = this->real * o.real - this->imaginary * o.imaginary;
    double ni = this->real * o.imaginary + this->imaginary * o.real;
    this->real = nr;
    this->imaginary = ni;
    return *this;
}

Complex& Complex::operator/=(const Complex& o)
{
    double denom = o.real * o.real + o.imaginary * o.imaginary;
    if (denom == 0.0)
    {
        throw std::runtime_error("Division by zero");
    }
    double nr = (this->real * o.real + this->imaginary * o.imaginary) / denom;
    double ni = (this->imaginary * o.real - this->real * o.imaginary) / denom;
    this->real = nr;
    this->imaginary = ni;
    return *this;
}

bool operator==(const Complex& a, const Complex& b)
{
    return a.real == b.real && a.imaginary == b.imaginary;
}

bool operator!=(const Complex& a, const Complex& b)
{
    return !(a == b);
}

Complex& Complex::operator=(const Complex& rhs)
{
    if (*this != rhs)
    {
        this->real = rhs.real;
        this->imaginary = rhs.imaginary;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << c.real;
    if (c.imaginary >= 0)
    {
        os << " + " << c.imaginary << "i";
    }
    else
    {
        os << " - " << -c.imaginary << "i";
    }
    return os;
}


#endif