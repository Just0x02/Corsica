#include <corsica/vec4.hpp>
#include <corsica/vec3.hpp>
#include <corsica/vec2.hpp>

#include <cmath>

using namespace Corsica;

Vec4::Vec4() : x(0.0), y(0.0), z(0.0)
{

}

Vec4::Vec4(f64 xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw)
{

}

Vec4::Vec4(f64 x, f64 y, f64 z, f64 w) : x(x), y(y), z(z), w(w)
{

}

f64 Vec4::length()
{
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vec4 Vec4::add(const Vec4& other)
{
    return Vec4(
        this->x + other.x, 
        this->y + other.y, 
        this->z + other.z,
        this->w + other.w
    );
}

Vec4 Vec4::sub(const Vec4& other)
{
    return Vec4(
        this->x - other.x, 
        this->y - other.y, 
        this->z - other.z,
        this->w - other.w
    );
}

Vec4 Vec4::mul(const Vec4& other)
{
    return Vec4(
        this->x * other.x, 
        this->y * other.y, 
        this->z * other.z,
        this->w * other.w
    );
}

f64 Vec4::dot(const Vec4& other)
{
    return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
}

Vec4 Vec4::cross(const Vec4& other)
{
    return Vec4(
        this->y * other.z - this->z * other.y,
        this->z * other.x - this->x * other.z,
        this->x * other.y - this->y * other.x,
        0.0
    );
}

std::string Vec4::as_string()
{
    return "Vec4(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) +  ", " + std::to_string(this->w) + ")"; 
}

std::array<f64, 4> Vec4::as_array()
{
    return { this->x, this->y, this->z, this->w };
}

// Vec4::operator Vec2()
// {
//     return Vec2(this->x, this->y);
// }

f64 Vec4::distance_to(const Vec4& other)
{
    f64 dx = this->x - other.x;
    f64 dy = this->y - other.y;
    f64 dz = this->z - other.z;
    f64 dw = this->w - other.w;

    return std::sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
}

Vec4 &Vec4::normalize()
{
    f64 len = this->length();
    
    if (len != 0)
    {
        this->x /= len;
        this->y /= len;
        this->z /= len;
        this->w /= len;
    }

    return *this;
}

Vec4 &Vec4::round()
{
    this->x = std::round(this->x);
    this->y = std::round(this->y);
    this->z = std::round(this->z);
    this->w = std::round(this->w);

    return *this;
}