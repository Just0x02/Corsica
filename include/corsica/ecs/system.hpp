#pragma once

#include <types.h>

#include <corsica/ecs/entity.hpp>

#include <vector>
#include <algorithm>

namespace Corsica::ECS
{
    template <class Derived>
    class System
    {
        public:
            std::vector<Entity*> entities;

            Derived& add_entity(Entity* entity);

            Derived& remove_entity(Entity* entity);

            bool has_entity(Entity* entity) const;

            virtual void update() {};
    };
};

#include "system.tpp"