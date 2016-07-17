#include "TestEntity.hpp"

TestEntity::TestEntity()
: Animation(std::string("test.json"))
{
    m_animator.play() << "test" << thor::Playback::loop("test");
}

void TestEntity::texture(const sf::Texture& texture)
{
    m_sprite.setTexture(texture, true);
}

void TestEntity::update(sf::Time dt)
{
    m_animator.update(dt);
    m_animator.animate(m_sprite);
}

void TestEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //states.transform *= getTransform();
    target.draw(m_sprite, states);
}
