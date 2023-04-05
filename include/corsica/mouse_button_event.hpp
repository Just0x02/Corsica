#pragma once

#include <types.h>

namespace Corsica
{
    struct MouseButtonEvent
    {
        i32 button;
        i32 action;
        i32 mods;

        MouseButtonEvent(i32 button, i32 action, i32 mods);
    };
};