#pragma once

#include <types.h>

namespace Corsica::ECS
{
    struct Component
    {
        virtual void init() {};
        virtual void update() {};

        virtual ~Component() {};
    };
};