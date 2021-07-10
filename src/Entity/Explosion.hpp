#pragma once

#include "Entity/Base/Entity.hpp"
#include "Entity/Base/Animation.hpp"

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
