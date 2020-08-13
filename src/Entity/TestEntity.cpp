#include "Entity/TestEntity.hpp"

TestEntity::TestEntity()
    : Animation{"test.json"}
{
    m_animator.play() << "test" << thor::Playback::loop("test");
}

void TestEntity::texture(const sf::Texture& texture)
{
    m_sprite.setTexture(texture, true);
}

void TestEntity::update(const sf::Time dt)
{
    m_animator.update(dt);
    m_animator.animate(m_sprite);
}

void TestEntity::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}
