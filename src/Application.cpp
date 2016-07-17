#include "Application.hpp"

#include "TestState.hpp"

#include <memory>

Application::Application()
: m_window{{1024, 768}, "SmallGameFramework", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings{0, 0, 8}}
{
    m_window.setVerticalSyncEnabled(true);
}

void Application::run()
{
    // Simple state machine
    std::unique_ptr<State> state(new TestState(m_window));

    while(state != nullptr)
    {
        state = state->run();
    }
}
