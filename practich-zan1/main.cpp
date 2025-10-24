#include <iostream>
#include <cstdint>
#include <stdexcept>


uint64_t gcd(uint64_t a, uint64_t b)
{
    while (b != 0)
    {
        uint64_t t = b;
        b = a % b;
        a = t;
    }
    return a;
}

class Fraction
{
private:
    uint64_t num;
    uint64_t den;
    bool neg;
    void normalizeFraction()
    {
        if (den == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        if (num == 0)
        {
            neg = false;
            den = 1;
        }
        uint64_t g = gcd(num, den);
        num /= g;
        den /= g;
    }
public:
    Fraction(int64_t numerator = 0, uint64_t denominator = 1)
    {
        num = 0;
        den = denominator;
        neg = false;
        if (denominator == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        if (numerator < 0)
        {
            neg = true;
            num = static_cast<uint64_t>(-numerator);
        }
        else
        {
            num = static_cast<uint64_t>(numerator);
        }
        normalizeFraction();
    }

    Fraction operator+ (const Fraction& rhs)
    {
        uint64_t g = gcd(den, rhs.den);
        uint64_t common_den = den / g * rhs.den;
        uint64_t lhs_abs = num * (common_den / den);
        uint64_t rhs_abs = rhs.num * (common_den / rhs.den);
        int64_t lhs_num = lhs_abs;
        if (neg)
        {
            lhs_num = -lhs_num;
        }
        int64_t rhs_num = rhs_abs;
        if (rhs.neg)
        {
            rhs_num = -rhs_num;
        }
        int64_t sum = lhs_num + rhs_num;
        bool result_neg;
        if (sum < 0)
        {
            result_neg = true;
        }
        else
        {
            result_neg = false;
        }
        uint64_t result_num;
        if (sum < 0)
        {
            result_num = -sum;
        }
        else
        {
            result_num = sum;
        }
        Fraction result;
        result.neg = result_neg;
        result.num = result_num;
        result.den = common_den;
        result.normalizeFraction();
        return result;
    }

    Fraction operator-(const Fraction& rhs)
    {
        uint64_t g = gcd(den, rhs.den);
        uint64_t common_den = den / g * rhs.den;
        uint64_t lhs_abs = num * (common_den / den);
        uint64_t rhs_abs = rhs.num * (common_den / rhs.den);
        int64_t lhs_num = lhs_abs;
        if (neg)
        {
            lhs_num = -lhs_num;
        }
        int64_t rhs_num = rhs_abs;
        if (rhs.neg)
        {
            rhs_num = -rhs_num;
        }
        int64_t diff = lhs_num - rhs_num;
        bool result_neg;
        if (diff < 0)
        {
            result_neg = true;
        }
        else
        {
            result_neg = false;
        }
        uint64_t result_num;
        if (diff < 0)
        {
            result_num = -diff;
        }
        else
        {
            result_num = diff;
        }
        Fraction result;
        result.neg = result_neg;
        result.num = result_num;
        result.den = common_den;
        result.normalizeFraction();
        return result;
    }


    Fraction operator*(const Fraction& rhs)
    {
        Fraction result;
        result.neg = neg ^ rhs.neg;
        result.num = num * rhs.num;
        result.den = den * rhs.den;
        result.normalizeFraction();
        return result;
    }

    Fraction operator/(const Fraction& rhs)
    {
        if (rhs.num == 0)
        {
            throw std::invalid_argument("Division by zero");
        }
        Fraction result;
        result.neg = neg ^ rhs.neg;
        result.num = num * rhs.den;
        result.den = den * rhs.num;
        result.normalizeFraction();
        return result;
    }

    void print()
    {
        if (neg && num != 0)
        {
            std::cout << '-' << num;
        }
        else if (num != 0)
        {
            std::cout << num;
        }
        if (den != 1)
        {
            std::cout << '/' << den;
        }
    }

//2zaniatie
    //Fraction operator~()
    //{
    //    return Fraction(this->den, this->num, this->neg);
    //}

    //Fraction operator/(Fraction& rhs) 
    //{
    //    if (this->den == 0)
    //    {
    //        throw std::invalid_argument("Division by zero");
    //    }
    //    return ((*this)*(~rhs));
    //}

    Fraction& operator++() //префикс
    {
        return ++(*this);
    }

    Fraction& operator++(int) //постфикс
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }  
    //3zaniatie
    Fraction& operator+=(const Fraction& rhs)
    {
        this->num += rhs.num * den;
        this->den = rhs.den; 
        normalizeFraction();
        return*this;
    }

    /*Fraction operator+(const int& lhs, const Fraction& rhs)
    {
        Fraction temp(*this);
        return temp += rhs;
    }*/

    Fraction& operator=(const Fraction& rhs)
    {
        if (this != &rhs)
        {
            num = rhs.num;
            den = rhs.den;
        }
        return *this;
    }
    //4zaniatie
    void setNum(const uint64_t num) 
    {
        this->num = num;
    }
    void setDen(const uint64_t den) 
    {
        if (den == 0) 
        {
            throw std::invalid_argument("Division by zero");
        }
        this->den = den;
    }
    void setNeg(const bool neg)
    {
        this->neg = neg;
    }
    uint64_t getNum() const 
    {
        return(this->num);
    }
    uint64_t getDen() const 
    {
        return(this->den);
    }
    bool getNeg() const 
    {
        return(this->neg);
    }

    //Fractiom(int _num, int _den) : num(_num), den(_den) {}; //способ передачи параметров
    //operator std::string() const;
    //operator double() const;

    //operator double() const
    //{
    //    int neg{1};
    //    if (this->neg) 
    //    {
    //        neg = -1;
    //    }
    //    return(static_cast<double>(this->getNum()) / this->getDen() * neg);
    //}

    explicit Fraction(const double d)
    {
        this->num = int(d * 100);
        this->den = 100;
        return(this->getNum()) / this->getDen();
    }
};


int main()
{
    try
    {
        Fraction a(-4, 12);     // -1/3
        Fraction b(5, 6);       //  5/6
        Fraction sum = a + b;   //  1/2
        Fraction diff = a - b;  // -7/6
        Fraction prod = a * b;  // -5/18
        Fraction quot = a / b;  // -2/5

        a.print();  std::cout << " + ";  b.print();  std::cout << " = "; sum.print();  std::cout << '\n';
        a.print();  std::cout << " - ";  b.print();  std::cout << " = "; diff.print(); std::cout << '\n';
        a.print();  std::cout << " * ";  b.print();  std::cout << " = "; prod.print(); std::cout << '\n';
        a.print();  std::cout << " : ";  b.print();  std::cout << " = "; quot.print(); std::cout << '\n';

        Fraction fraction(1, 2);
        double d = fraction;
        std::cout << d;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}
