#pragma once

#include "State.hpp"
#include "TestEntity.hpp"

#include <Thor/Resources.hpp>

#include <string>

class TestState : public State
{
public:
    TestState(sf::RenderWindow& window);

private:
    void process_events() final;
    void update(const sf::Time dt) final;
    void render() final;

    void load_resources();

private:
    thor::ResourceHolder<sf::Texture, std::string> m_textures;
    thor::ResourceHolder<sf::Font, std::string> m_fonts;

    TestEntity m_ent;
};