#ifndef __CORSICA_ECS_SYSTEM_TPP__
#define __CORSICA_ECS_SYSTEM_TPP__

#include "system.hpp"

template <typename Derived>
Derived& Corsica::ECS::System<Derived>::add_entity(Entity* entity)
{
    this->entities.push_back(entity);
    return static_cast<Derived&>(*this);
}

template <typename Derived>
Derived& Corsica::ECS::System<Derived>::remove_entity(Entity* entity)
{
    auto iter = std::find(this->entities.begin(), this->entities.end(), entity);

    if (iter != this->entities.end())
    {
        this->entities.erase(iter);
    }

    return static_cast<Derived&>(*this);
}

template <typename Derived>
bool Corsica::ECS::System<Derived>::has_entity(Entity* entity) const
{
    auto iter = std::find(this->entities.begin(), this->entities.end(), entity);
    return iter != this->entities.end();
}

#endif /* __CORSICA_ECS_SYSTEM_TPP__ */
