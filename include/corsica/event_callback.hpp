#pragma once

#include <types.h>

#include <corsica/event_context.hpp>

#include <functional>
#include <string>

namespace Corsica
{
    struct EventCallback
    {
        bool enabled;
        std::function<void(EventContext&)> cb;

        EventCallback(std::function<void(EventContext&)> cb);
    };
};