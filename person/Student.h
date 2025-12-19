#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"


class Student : public Person
{
private:
    int course;
    int32_t group;
public:
    Student(const char* name = "", int course = 1, int group);
    ~Student() override;
    void SetCourse(int course);
    void SetGroup(int32_t group);
    int GetCourse() const;
    int GetGroup() const;
    void PrintInfo() const override;
};


#endif