#ifndef CLASS3D_H
#define CLASS3D_H
#include "class2D.h"

class Point3D : public Point2D
{
protected:
    int z;
public:
    Point3D(int x = 0, int y = 0, int z = 0);
    ~Point3D() = default;
    Point3D(const Point3D&) = default;
    Point3D(Point3D&&) = default;
    Point3D& operator=(const Point3D& rhs) = default;
    Point3D& operator+=(const Point3D& rhs);
    Point3D& operator-=(const Point3D& rhs);
    Point3D& operator*=(const Point3D& rhs);
    friend Point3D operator+(Point3D lhs, const Point3D& rhs);
    friend Point3D operator-(Point3D lhs, const Point3D& rhs);
    friend Point3D operator*(Point3D lhs, const Point3D& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Point3D& rhs);
};


Point3D::Point3D(int x, int y, int z) : Point2D(x, y), z(z)
{
}

Point3D& Point3D::operator+=(const Point3D& rhs)
{
    Point2D::operator+=(rhs); 
    this->z += rhs.z;
    return *this;
}

Point3D& Point3D::operator-=(const Point3D& rhs)
{
    Point2D::operator-=(rhs);
    this->z -= rhs.z;
    return *this;
}

Point3D& Point3D::operator*=(const Point3D& rhs)
{
    Point2D::operator*=(rhs);
    this->z *= rhs.z;
    return *this;
}

Point3D operator+(Point3D lhs, const Point3D& rhs)
{
    lhs += rhs;
    return lhs;
}

Point3D operator-(Point3D lhs, const Point3D& rhs)
{
    lhs -= rhs;
    return lhs;
}

Point3D operator*(Point3D lhs, const Point3D& rhs)
{
    lhs *= rhs;
    return lhs;
}

std::ostream& operator<<(std::ostream& os, const Point3D& rhs)
{
    os << static_cast<const Point2D&>(rhs) << ", " << rhs.z << ')';
    return os;
}


#endif