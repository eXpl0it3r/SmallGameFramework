#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{
public:
    virtual ~Entity() = default;

    virtual void update(sf::Time delta_time) = 0;
};
