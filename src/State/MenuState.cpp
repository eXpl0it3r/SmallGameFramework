#include "State/MenuState.hpp"

struct Resources;

MenuState::MenuState(sf::RenderWindow& window, Resources& resources)
    : State{ window, resources }
    , m_mouse_button_released{ false }
    , m_exit{ "Exit", m_resources }
{
    const auto window_size = sf::Vector2f{ window.getSize() };

    m_exit.setPosition({ window_size.x / 2, window_size.y / 2 });
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

void MenuState::update(const sf::Time delta_time)
{
    processEvents();

    if (m_exit.globalBounds().contains(m_current_mouse_position))
    {
        m_exit.mouseOver();

        if (m_mouse_button_released)
        {
            m_window.close();
        }
    }
    else
    {
        m_exit.mouseLeave();
    }
}

void MenuState::render()
{
    m_window.clear();
    m_window.draw(m_exit);
    m_window.display();
}
