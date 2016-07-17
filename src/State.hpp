#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

class State
{
public:
    State(sf::RenderWindow& window);
    virtual ~State() = default;

    // Non copyable
    State(State const&) = delete;
    State& operator=(State const&) = delete;

    std::unique_ptr<State> run();

protected:
    virtual void process_events() = 0;
    virtual void update(const sf::Time dt) = 0;
    virtual void render() = 0;

protected:
    sf::RenderWindow& m_window;

    std::unique_ptr<State> m_next;
};