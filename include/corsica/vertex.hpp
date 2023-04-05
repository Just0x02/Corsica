#pragma once

#include <types.h>
#include <corsica/gfx.hpp>
#include <corsica/vec4.hpp>

namespace Corsica
{
    struct Vertex
    {
        Vec3 position;
        Vec4 color; 
        Vec2 tex_coord;
    };
};