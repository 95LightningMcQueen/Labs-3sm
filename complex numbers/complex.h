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
    Complex(double = 0, double = 0);
    Complex(const Complex& other);
    Complex(Complex&& other) noexcept;
    Complex& operator=(Complex&& other) noexcept;
    ~Complex();
    double getReal() const;
    double getImag() const;
    double abs() const;
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
    Complex& operator++(); //преф
    Complex operator++(int); // постф
    Complex& operator--(); // преф 
    Complex operator--(int); // постф
    friend Complex operator+(const Complex& a, const double num);
    friend Complex operator+(double num, const Complex& a);
    friend Complex operator-(const Complex& a, const double num);
    friend Complex operator-(double num, const Complex& a);
};
#endif
