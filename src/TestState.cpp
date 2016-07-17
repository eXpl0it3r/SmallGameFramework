#include "TestState.hpp"

TestState::TestState(sf::RenderWindow& window)
: State{window}
{
    load_resources();

    m_ent.texture(m_textures["test"]);
}

void TestState::process_events()
{
    sf::Event event;

    while(m_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            m_window.close();
    }
}

void TestState::update(const sf::Time dt)
{
    process_events();

    m_ent.update(dt);
}

void TestState::render()
{
    m_window.clear();
    m_window.draw(m_ent);
    m_window.display();
}

void TestState::load_resources()
{
    m_textures.acquire("test", thor::Resources::fromFile<sf::Texture>("test.png"));
}