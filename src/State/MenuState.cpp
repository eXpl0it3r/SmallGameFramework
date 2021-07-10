#include "State/MenuState.hpp"

#include <cmath>

#include "State/PlayState.hpp"

struct Resources;

MenuState::MenuState(sf::RenderWindow& window, Resources& resources)
    : State{ window, resources }
    , m_mouse_button_released{ false }
    , m_start{ "Start", m_resources }
    , m_options{ "Options", m_resources }
    , m_exit{ "Exit", m_resources }
{
    const auto window_size = sf::Vector2f{ window.getSize() };

    m_start.setPosition(sf::Vector2f{ window_size.x / 2, window_size.y / 2 } - sf::Vector2f{ 0.f, std::round(m_exit.globalBounds().height * 2.5f) });
    m_options.setPosition({ window_size.x / 2, window_size.y / 2 });
    m_exit.setPosition(sf::Vector2f{ window_size.x / 2, window_size.y / 2 } + sf::Vector2f{ 0.f, std::round(m_exit.globalBounds().height * 2.5f) });
}

void MenuState::processEvents()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
        else if (event.type == sf::Event::MouseMoved)
        {
            m_current_mouse_position = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            m_current_mouse_position = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
            m_mouse_button_released = true;
        }
        else
        {
            m_mouse_button_released = false;
        }
    }
}

void MenuState::handleButtonMouseInteraction(Button& button) const
{
    if (button.globalBounds().contains(m_current_mouse_position))
    {
        button.mouseOver();
    }
    else
    {
        button.mouseLeave();
    }
}

void MenuState::update(const sf::Time delta_time)
{
    processEvents();

    handleButtonMouseInteraction(m_start);
    handleButtonMouseInteraction(m_options);
    handleButtonMouseInteraction(m_exit);

    if (m_start.globalBounds().contains(m_current_mouse_position) && m_mouse_button_released)
    {
        m_next = std::make_unique<PlayState>(m_window, m_resources);
    }
    if (m_exit.globalBounds().contains(m_current_mouse_position) && m_mouse_button_released)
    {
        m_window.close();
    }
}

void MenuState::render()
{
    m_window.clear();
    m_window.draw(m_start);
    m_window.draw(m_options);
    m_window.draw(m_exit);
    m_window.display();
}
