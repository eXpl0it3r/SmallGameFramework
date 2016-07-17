#pragma once

#include "Entity.hpp"
#include "Animation.hpp"

#include <Thor/Animations.hpp>

#include <vector>

class TestEntity : public Entity, public Animation
{
public:
    TestEntity();

    void texture(const sf::Texture& texture);

    void update(sf::Time dt) final;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

private:
    sf::Sprite m_sprite;
};