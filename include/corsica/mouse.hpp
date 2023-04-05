#pragma once

#include <types.h>

#include <corsica/gfx.hpp>
#include <corsica/button.hpp>
#include <corsica/vec2.hpp>

namespace Corsica
{
    struct Mouse
    {
        Button buttons[GLFW_MOUSE_BUTTON_LAST];
        Vec2 position, delta;

        static void set_grabbed(bool grabbed);
        static bool is_grabbed();
    };
};