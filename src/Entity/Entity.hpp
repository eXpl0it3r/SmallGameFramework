#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{
public:
    virtual void update(sf::Time delta_time) = 0;

protected:
    Entity() = default;
    ~Entity() override = default;

    Entity(const Entity&) = default;
    Entity& operator=(const Entity&) = default;

    Entity(Entity&&) noexcept = default;
    Entity& operator=(Entity&&) noexcept = default;
};
