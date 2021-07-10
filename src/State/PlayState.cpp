#include "State/PlayState.hpp"
#include "Core/Resources.hpp"

PlayState::PlayState(sf::RenderWindow& window, Resources& resources)
    : State{ window, resources }
    , m_explosion{ m_resources.Textures[Texture::Explosion] }
{
}

void PlayState::processEvents()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }
}

void PlayState::update(const sf::Time delta_time)
{
    processEvents();

    m_explosion.update(delta_time);
}

void PlayState::render()
{
    m_window.clear();
    m_window.draw(m_explosion);
    m_window.display();
}
