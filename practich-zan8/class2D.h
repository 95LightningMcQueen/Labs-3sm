#ifndef CLASS2D_H
#define CLASS2D_H
#include <iostream>


class Point2D
{
protected:
    int x;
    int y;
public:
    Point2D(int x = 0, int y = 0);
    ~Point2D() = default;
    Point2D(const Point2D&) = default;
    Point2D(Point2D&&) = default;
    Point2D& operator=(const Point2D& rhs);
    void SetX(int x);
    void SetY(int y);
    int GetX() const;
    int GetY() const;
    Point2D& operator+=(const Point2D& rhs);
    Point2D& operator-=(const Point2D& rhs);
    Point2D& operator*=(const Point2D& rhs);
    friend Point2D operator+(Point2D lhs, const Point2D& rhs);
    friend Point2D operator-(Point2D lhs, const Point2D& rhs);
    friend Point2D operator*(Point2D lhs, const Point2D& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Point2D& p);
};


Point2D::Point2D(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point2D::SetX(int x)
{
    this->x = x;
}

void Point2D::SetY(int y)
{
    this->y = y;
}

int Point2D::GetX() const
{
    return this->x;
}

int Point2D::GetY() const
{
    return this->y;
}

Point2D& Point2D::operator=(const Point2D& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}

Point2D& Point2D::operator+=(const Point2D& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Point2D& Point2D::operator-=(const Point2D& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

Point2D& Point2D::operator*=(const Point2D& rhs)
{
    this->x *= rhs.x;
    this->y *= rhs.y;
    return *this;
}

Point2D operator+(Point2D lhs, const Point2D& rhs)
{
    lhs += rhs;
    return lhs;
}

Point2D operator-(Point2D lhs, const Point2D& rhs)
{
    lhs -= rhs;
    return lhs;
}

Point2D operator*(Point2D lhs, const Point2D& rhs)
{
    lhs *= rhs;
    return lhs;
}

std::ostream& operator<<(std::ostream& os, const Point2D& rhs)
{
    os << '(' << rhs.x << ", " << rhs.y << ')';
    //      os << <<static_cast<const Point2D&>(rhs); для класса 3д
    return os;
}


#endif


/*
int main()
{
Point2D* arr[5]; // Point2D** arr = new Point2D* [5];
Point3D p = (9, 11,67);
Point2D po = (14, 88);
arr[0] = &p;
arr[1] = new Point2D (42, 42);
arr[2] = new Point3D (52, 52, 52);
arr[3] = &po;
}

*/