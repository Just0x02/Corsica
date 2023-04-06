#ifndef __CORSICA_ECS_ENTITY_TPP__
#define __CORSICA_ECS_ENTITY_TPP__

#include <iostream>

#include "entity.hpp"

void Corsica::ECS::Entity::update()
{
    for (auto& comp : components)
        comp.second->update();
}

template <class T>
bool Corsica::ECS::Entity::has_component() const
{
    return this->components.count(std::string(typeid(T).name()));
}

template <class T>
T& Corsica::ECS::Entity::get_component() const
{
    auto ptr(this->components.find(std::string(typeid(T).name())));

    std::cout << "GETTING COMPONENT WITH NAME: " << ptr->first << " => " << ptr->second << std::endl;

    if (ptr == this->components.end())
    {
        throw std::runtime_error("Entity does not have component");
    }

    return *reinterpret_cast<T*>(ptr->second);
}

template<class T, typename... TArgs>
T& Corsica::ECS::Entity::add_component(TArgs&&... args)
{
    T* component(new T(std::forward<TArgs>(args)...));
    // component->entity = this;
    components[std::string(typeid(*component).name())] = component;
    std::cout << "ADDED COMPONENT WITH NAME: " << std::string(typeid(*component).name()) << std::endl;

    component->init();
    return *component;
}

#endif /* __CORSICA_ECS_ENTITY_TPP__ */
