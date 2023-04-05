#pragma once

#include <types.h>

#include <corsica/rgb.hpp>

#include <string>
#include <array>

namespace Corsica
{
    struct RGBA
    {
        u8 r, g, b, a;

        RGBA();
        RGBA(u32 rgba);
        RGBA(u8 r, u8 g, u8 b, u8 a);

        std::array<u8, 4> as_array();
        std::string as_string();

        operator u32();
        // operator RGB();
    };
};