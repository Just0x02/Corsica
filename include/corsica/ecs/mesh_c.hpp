#pragma once

#include <types.h>

#include <corsica/ecs/component.hpp>

#include <corsica/mesh2d.hpp>

namespace Corsica::ECS
{
    struct MeshComponent : public Component
    {
        Mesh2D *mesh;

        MeshComponent(Mesh2D *mesh) : mesh(mesh) {};
    };
};