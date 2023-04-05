#include <corsica/vec3.hpp>
#include <corsica/vec2.hpp>

#include <cmath>

using namespace Corsica;

Vec3::Vec3() : x(0.0), y(0.0), z(0.0)
{

}

Vec3::Vec3(f64 xyz) : x(xyz), y(xyz), z(xyz)
{

}

Vec3::Vec3(f64 x, f64 y, f64 z) : x(x), y(y), z(z)
{

}

f64 Vec3::length()
{
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vec3 Vec3::add(const Vec3& other)
{
    return Vec3(
        this->x + other.x, 
        this->y + other.y, 
        this->z + other.z
    );
}

Vec3 Vec3::sub(const Vec3& other)
{
    return Vec3(
        this->x - other.x, 
        this->y - other.y, 
        this->z - other.z
    );
}

Vec3 Vec3::mul(const Vec3& other)
{
    return Vec3(
        this->x * other.x, 
        this->y * other.y, 
        this->z * other.z
    );
}

f64 Vec3::dot(const Vec3& other)
{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vec3 Vec3::cross(const Vec3& other)
{
    return Vec3(this->y * other.z - this->z * other.y,
                this->z * other.x - this->x * other.z,
                this->x * other.y - this->y * other.x);
}

std::string Vec3::as_string()
{
    return "Vec3(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ")"; 
}

std::array<f64, 3> Vec3::as_array()
{
    return { this->x, this->y, this->z };
}

// Vec3::operator Vec2()
// {
    // return Vec2(this->x, this->y);
// }

f64 Vec3::distance_to(const Vec3& other)
{
    f64 dx = this->x - other.x;
    f64 dy = this->y - other.y;
    f64 dz = this->z - other.z;

    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

Vec3 &Vec3::normalize()
{
    f64 len = this->length();
    
    if (len != 0)
    {
        this->x /= len;
        this->y /= len;
        this->z /= len;
    }

    return *this;
}

Vec3 &Vec3::round()
{
    this->x = std::round(this->x);
    this->y = std::round(this->y);
    this->z = std::round(this->z);

    return *this;
}