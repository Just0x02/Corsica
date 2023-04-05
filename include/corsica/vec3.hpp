#pragma once

#include <types.h>

#include <corsica/vec2.hpp>

#include <string>
#include <array>

namespace Corsica
{
    struct Vec3
    {
        f64 x, y, z;

        Vec3();
        Vec3(f64 xyz);
        Vec3(f64 x, f64 y, f64 z);
        Vec3(Vec2 base, f64 z);

        f64 length();
                
        Vec3 add(const Vec3 &other);
        Vec3 sub(const Vec3 &other);
        Vec3 mul(const Vec3 &other);
        
        Vec3 cross(const Vec3 &other);
        
        Vec3 &normalize();
        Vec3 &round();

        f64 dot(const Vec3 &other);
        f64 distance_to(const Vec3 &other);

        std::string as_string();
        std::array<f64, 3> as_array();
    };
};