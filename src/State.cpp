#include "State.hpp"

State::State(sf::RenderWindow& window)
: m_window{window}
{

}

std::unique_ptr<State> State::run()
{
    sf::Clock clock;
    sf::Time last_frametime;
    sf::Time dt;

    while(m_next == nullptr && m_window.isOpen())
    {
        dt = clock.getElapsedTime() - last_frametime;
        last_frametime = clock.getElapsedTime();

        update(dt);
        render();
    }

    return std::move(m_next);
}