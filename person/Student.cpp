#include "Student.h"


Student::Student(const char* name, int course, int group) : Person(name), course(course), group(group) {}

Student::~Student() {}

void Student::SetCourse(int course)
{
    this->course = course;
}

void Student::SetGroup(int32_t group)
{
    this->group = group;
}

int Student::GetCourse() const
{
    return course;
}

int Student::GetGroup() const
{
    return group;
}

void Student::PrintInfo() const
{
    std::cout << "Student " << GetFullName() << '\n';
    std::cout << "Course: " << course << ", Group: " << group << '\n';
}