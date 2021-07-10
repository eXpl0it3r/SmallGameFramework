#include "State/TestState.hpp"
#include "Core/Resources.hpp"

TestState::TestState(sf::RenderWindow& window, Resources& resources)
    : State{ window, resources }
{
    loadResources();
}

void TestState::processEvents()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }
}

void TestState::update(const sf::Time delta_time)
{
    processEvents();

    m_ent.update(delta_time);
}

void TestState::render()
{
    m_window.clear();
    m_window.draw(m_ent);
    m_window.display();
}

void TestState::loadResources() const
{
    m_resources.Textures.acquire("test", thor::Resources::fromFile<sf::Texture>("test.png"));
}
