#pragma once

#include <types.h>

#include <corsica/vec2.hpp>
#include <corsica/vec3.hpp>

#include <string>
#include <array>

namespace Corsica
{
    struct Vec4
    {
        f64 x, y, z, w;

        Vec4();
        Vec4(f64 xyzw);
        Vec4(f64 x, f64 y, f64 z, f64 w);

        f64 length();
                
        Vec4 add(const Vec4 &other);
        Vec4 sub(const Vec4 &other);
        Vec4 mul(const Vec4 &other);
        
        Vec4 cross(const Vec4 &other);
        
        Vec4 &normalize();
        Vec4 &round();

        f64 dot(const Vec4 &other);
        f64 distance_to(const Vec4 &other);

        std::string as_string();
        std::array<f64, 4> as_array();

        // operator Vec2();
        // operator Vec3();
    };
};