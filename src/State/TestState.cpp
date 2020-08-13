#include "State/TestState.hpp"

TestState::TestState(sf::RenderWindow& window)
    : State{window}
{
    loadResources();

    m_ent.texture(m_textures["test"]);
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

void TestState::loadResources()
{
    m_textures.acquire("test", thor::Resources::fromFile<sf::Texture>("test.png"));
}
