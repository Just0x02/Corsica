#pragma once

#include <types.h>

#include <corsica/ecs/component.hpp>

#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <string>

namespace Corsica::ECS
{
    class Entity
    {
    private:
        std::unordered_map<std::string, Component*> components;

    public:
        void update();

        template <class T>
        bool has_component() const;

        template <class T>
        T& get_component() const;

        template <class T, typename... TArgs>
        T& add_component(TArgs&&... args);
    };
};

#include "entity.tpp"