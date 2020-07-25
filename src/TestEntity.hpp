#pragma once

#include "Entity.hpp"
#include "Animation.hpp"

#include <Thor/Animations.hpp>

class TestEntity final : public Entity, public Animation
{
public:
    TestEntity();

    void texture(const sf::Texture& texture);

    void update(sf::Time dt) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite m_sprite;
};
