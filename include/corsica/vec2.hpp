#pragma once

#include <types.h>

#include <string>
#include <array>
#include <algorithm>

namespace Corsica
{
    struct Vec2
    {
        f64 x, y;

        Vec2();
        Vec2(f64 xy);
        Vec2(f64 x, f64 y);

        f64 length();
                
        Vec2 add(const Vec2 &other);
        Vec2 sub(const Vec2 &other);
        Vec2 mul(const Vec2 &other);
        Vec2 div(const Vec2 &other);

        Vec2 lerp(const Vec2 &other, f32 t);
        
        Vec2 &normalize();
        Vec2 &round();

        f64 dot(const Vec2 &other);
        f64 distance_to(const Vec2 &other);

        std::string as_string();
        std::array<f64, 2> as_array();

        Vec2 &clamp_x(f64 min, f64 max);
        Vec2 &clamp_y(f64 min, f64 max);
        Vec2 &clamp_xy(f64 min, f64 max);

        // operator Vec3();
    };
};