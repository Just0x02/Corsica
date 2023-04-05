#pragma once

#include <types.h>

#include <string>

namespace Corsica
{
    struct EventContext
    {
        std::string event_id;
        u8 *raw_data;
        bool allow_passthrough;
    };
};