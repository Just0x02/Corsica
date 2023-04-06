#pragma once

#include <types.h>

#include <corsica/ecs/component.hpp>

#include <corsica/shader.hpp>

namespace Corsica::ECS
{
    struct ShaderComponent : public Component
    {
        Shader shader;

        ShaderComponent(Shader shader) : shader(shader) {};
    };
};