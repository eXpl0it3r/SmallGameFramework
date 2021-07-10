#pragma once

#include "Entity/Entity.hpp"
#include "Entity/Animation.hpp"

#include <Thor/Animations.hpp>

class Explosion final : public Entity, public Animation
{
public:
    explicit Explosion(const sf::Texture& texture);

    void update(sf::Time delta_time) override;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite m_sprite;
};
