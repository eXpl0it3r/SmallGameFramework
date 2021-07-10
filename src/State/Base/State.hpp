#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

struct Resources;

class State
{
public:
    explicit State(sf::RenderWindow& window, Resources& resources);
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
    Resources& m_resources;

    std::unique_ptr<State> m_next;
};
