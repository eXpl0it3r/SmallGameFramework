#include "Entity/Explosion.hpp"

Explosion::Explosion(const sf::Texture& texture)
    : Animation{ "explosion.json" }
{
    m_animator.play() << "explosion" << thor::Playback::loop("explosion");
    m_sprite.setTexture(texture, true);
}

void Explosion::update(const sf::Time delta_time)
{
    m_animator.update(delta_time);
    m_animator.animate(m_sprite);
}

void Explosion::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}
