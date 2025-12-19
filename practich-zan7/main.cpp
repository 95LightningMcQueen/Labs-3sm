#include <iostream>
#include <string>


class Human
{
protected:
	std::string name;
	int age;
	int dni;
public:
	void Speak()
	{
		std::cout << "privet, ya " << name << " mne " << age << '\n';
		std::cout << "dney do dembelya: " << dni;
	}
	Human(std::string name = "heze kto", int age = 0, int dni = 0)
	{
		this->name = name;
		this->age = age;
		this->dni = dni;
	}
	~Human()
	{
		std::cout << "\ndestuct Human";
	}

};

class Curseant : public Human
{
protected:
	int urovenEboshera;
	std::string zvanie;
public:
	Curseant(int urovenEboshera = 0, std::string zvanie = "ryadovoy")
	{
		this->urovenEboshera = urovenEboshera;
		this->zvanie = zvanie;
	}
	~Curseant()
	{
		std::cout << "\ndestruct Curseant";
	}
};

class Ded : public Curseant
{
protected:
	std::string zvanie;
	std::string pogonyalo;
public:
	Ded(std::string zvanie = " ", std::string pogonyalo = " ")
	{
		this->zvanie = "sergant";
		this->pogonyalo = "ded";
	}
	~Ded()
	{
		std::cout << "\ndestuct Human";
	}
};

int main()
{
	Human drun("Glushkovek", 18, 1500);
	drun.Speak();
	Curseant drun2(100, "sergant");
	drun2.Speak();


	return 0;
}