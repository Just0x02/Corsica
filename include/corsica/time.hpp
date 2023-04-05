#pragma once

#include <types.h>
#include <chrono>

#define NS_PER_SECOND (1000000000)
#define NS_PER_MS (1000000)

namespace Corsica::Time
{
    u64 get_now_ns();
    u64 get_now_ms();
    u64 get_now_mi();
};