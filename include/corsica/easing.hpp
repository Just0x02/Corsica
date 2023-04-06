#pragma once

#include <types.h>

#include <cmath>
#include <algorithm>

namespace Corsica::Easing
{
    template <typename A, typename B>
    f64 smoothstep(A edge0, B edge1, f32 t) 
    {
        // Scale, bias and saturate x to 0..1 range
        t = (f32) std::clamp((t - edge0) / (edge1 - edge0), 0.0f, 1.0f);
        
        // Evaluate polynomial
        return t * t * (3 - 2 * t);
    }

    template <typename A, typename B>
    f64 ease_out(A edge0, B edge1, f32 t)
    {
        return std::lerp(edge0, edge1, std::sqrt(t));
    }

    template <typename A>
    f64 fade(A t)
    {
        return t * t * t * (t * (t * 6 - 15) - 10);
    }

    f64 grad(i32 hash, f64 x, f64 y, f64 z)
    {
        i32 h = hash & 15;
        f64 u = h < 8 ? x : y,
            v = h < 4 ? x : h == 12 || h == 14 ? x : z;
        return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
    }
};