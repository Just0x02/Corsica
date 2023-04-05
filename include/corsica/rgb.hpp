#pragma once

#include <types.h>

#include <corsica/rgba.hpp>

#include <string>
#include <array>

#define __CORSICA_WHITE RGB(255, 255, 255)
#define __CORSICA_BLACK RGB(  0,   0,   0)

namespace Corsica
{
    struct RGB
    {
        u8 r, g, b;

        RGB();
        RGB(u32 rgb);
        RGB(u8 r, u8 g, u8 b);

        std::array<u8, 3> as_array();
        std::string as_string();
        std::string as_escape_code();

        operator u32();
    };
};