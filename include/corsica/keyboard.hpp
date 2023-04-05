#pragma once

#include <types.h>

#include <corsica/gfx.hpp>
#include <corsica/button.hpp>

namespace Corsica
{
    struct Keyboard
    {
        Button keys[GLFW_KEY_LAST];
    };
};