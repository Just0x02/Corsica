#include <corsica/vec2.hpp>
#include <corsica/vec3.hpp>

#include <cmath>
#include <algorithm>

using namespace Corsica;

Vec2::Vec2() : x(0.0), y(0.0)
{

}

Vec2::Vec2(f64 xy) : x(xy), y(xy)
{

}

Vec2::Vec2(f64 x, f64 y) : x(x), y(y)
{

}

f64 Vec2::length()
{
    return std::sqrt(this->x * this->x + this->y * this->y);
}

Vec2 Vec2::add(const Vec2 &other)
{
    return Vec2(this->x + other.x, this->y + other.y);
}

Vec2 Vec2::sub(const Vec2 &other)
{
    return Vec2(this->x - other.x, this->y - other.y);
}

Vec2 Vec2::mul(const Vec2 &other)
{
    return Vec2(this->x * other.x, this->y * other.y);
}

Vec2 Vec2::div(const Vec2 &other)
{
    return Vec2(this->x / other.x, this->y / other.y);
}

f64 Vec2::dot(const Vec2 &other)
{
    return this->x * other.x + this->y * other.y;
}

f64 Vec2::distance_to(const Vec2& other)
{
    f64 dx = this->x - other.x;
    f64 dy = this->y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

Vec2 &Vec2::round()
{
    this->x = std::round(this->x);
    this->y = std::round(this->y);

    return *this;
}

Vec2 &Vec2::normalize()
{
    f64 len = this->length();
    
    if (len != 0)
    {
        this->x /= len;
        this->y /= len;
    }

    return *this;
}

std::string Vec2::as_string()
{
    return "Vec2(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")"; 
}

std::array<f64, 2> Vec2::as_array()
{
    return { this->x, this->y };
}

Vec2 &Vec2::clamp_x(f64 min, f64 max)
{
    this->x = std::clamp(this->x, min, max);

    return *this;
}

Vec2 &Vec2::clamp_y(f64 min, f64 max)
{
    this->y = std::clamp(this->y, min, max);

    return *this;
}

Vec2 &Vec2::clamp_xy(f64 min, f64 max)
{
    return this->clamp_x(min, max).clamp_y(min, max);
}

Vec2 Vec2::lerp(const Vec2 &other, f32 t)
{
    
}

// Vec2::operator Vec3()
// {
//     return Vec3(this->x, this->y, 0.0);
// }

