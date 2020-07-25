#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

class State
{
public:
    explicit State(sf::RenderWindow& window);
    virtual ~State() = default;

    State(const State&) = delete;
    State& operator=(const State&) = delete;

    State(State&&) = default;
    State& operator=(State&&) = default;

    std::unique_ptr<State> run();

protected:
    virtual void processEvents() = 0;
    virtual void update(sf::Time delta_time) = 0;
    virtual void render() = 0;

    sf::RenderWindow& m_window;

    std::unique_ptr<State> m_next;
};
