#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>


class Person
{
protected:
    char* fullName;
public:
    Person(const char* name = "");
    Person(const Person& other);
    Person(Person&& other);
    Person& operator=(const Person& other);
    virtual ~Person();
    void SetFullName(const char* name);
    const char* GetFullName() const;
    virtual void PrintInfo() const;
};

#endif