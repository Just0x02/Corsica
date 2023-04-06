#pragma once

#include <types.h>

#include <corsica/ecs/component.hpp>

#include <corsica/texture.hpp>

namespace Corsica::ECS
{
    struct TextureComponent : public Component
    {
        Texture2D texture;

        TextureComponent(Texture2D texture) : texture(texture) {};
    };
};