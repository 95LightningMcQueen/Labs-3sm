#include "Person.h"


Person::Person(const char* name)
{
    fullName = new char[std::strlen(name) + 1];
    std::strcpy(fullName, name);
}

Person::Person(Person&& other)
{
    fullName = other.fullName;
    other.fullName = nullptr; 
}

Person& Person::operator=(const Person& other) 
{
    if (this == &other) 
    {
        return *this; 
    }

    return *this; 
}

Person::~Person()
{
    delete[] fullName;
}

void Person::SetFullName(const char* name)
{
    delete[] fullName;
    fullName = new char[std::strlen(name) + 1];
    std::strcpy(fullName, name);
}

const char* Person::GetFullName() const
{
    return fullName;
}

void Person::PrintInfo() const
{
    std::cout << "Name: " << GetFullName();
}