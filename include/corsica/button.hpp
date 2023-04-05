#pragma once

#include <types.h>

namespace Corsica
{
    struct Button
    {
        bool down;
        u64 pressed_tick, released_tick;

        u64 ticks_since_pressed();
        u64 ticks_since_released();
    };
};