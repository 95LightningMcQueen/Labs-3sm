#include <iostream>
#include <cstdint>
#include <stdexcept>
#include <numeric>


int64_t gcd(uint64_t a, uint64_t b)
{
	if (b > a)
	{
		std::swap(a, b);
	}
	if (b == 0) 
	{
		return a;
	}
	return gcd(b, a % b);
}

class Fraction
{
private:
	uint64_t num;
	uint64_t denum;
	bool neg;
	void simplify(uint64_t num, uint64_t denum)
	{
		uint64_t NOD = gcd(num, denum);
		this->num /= NOD;
		this->denum /= NOD;
	}
public:
	Fraction operator+ (const Fraction& rhs)
	{
		return Fraction();
	}
	Fraction(uint64_t num, uint64_t denum)
	{
		if (denum == 0)
		{
			throw "\ndenum cant be 0!";
		}
		this->num = num;
		this->denum = denum;
		std::cout << "num = " << num << '\n' << "denum = " << denum << '\n';
		this->simplify(num, denum);


	}
};


int main()
{
	try 
	{
		Fraction(4, 12);
	}
	catch (...)
	{
		std::cerr << "\ndenum cant be 0!";
	}

	return 0;
} //реализовать сложение от странного наальнпика и реализовать операторы плюс умножитбь минус делить 