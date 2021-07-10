#include "Application.hpp"

#include "State/MenuState.hpp"

#include <memory>

Application::Application()
    : m_window{ { 1024, 768 }, "SmallGameFramework", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings{ 0, 0, 8 } }
{
    m_window.setVerticalSyncEnabled(true);
}

void Application::run()
{
    loadResources();

    // Simple state machine
    std::unique_ptr<State> state = std::make_unique<MenuState>(m_window, m_resources);

    while (state != nullptr)
    {
        state = state->run();
    }
}

void Application::loadResources()
{
    m_resources.Fonts.acquire(Font::SpaceGrotesk, thor::Resources::fromFile<sf::Font>("SpaceGrotesk-Regular.ttf"));
    m_resources.Textures.acquire(Texture::Explosion, thor::Resources::fromFile<sf::Texture>("explosion.png"));
}
