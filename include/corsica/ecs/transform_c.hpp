#pragma once

#include <types.h>

#include <corsica/ecs/component.hpp>

#include <corsica/vec3.hpp>

namespace Corsica::ECS
{
    struct TransformComponent : public Component
    {
        Vec3 position;
        f32 rotation;
        f32 scale;

        TransformComponent(Vec3 position, f32 rotation, f32 scale) : position(position), rotation(rotation), scale(scale) {};
    };
};