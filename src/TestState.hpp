#pragma once

#include "State.hpp"
#include "TestEntity.hpp"

#include <Thor/Resources.hpp>

#include <string>

class TestState final : public State
{
public:
    explicit TestState(sf::RenderWindow& window);

private:
    void processEvents() override;
    void update(sf::Time delta_time) override;
    void render() override;

    void loadResources();

    thor::ResourceHolder<sf::Texture, std::string> m_textures;
    thor::ResourceHolder<sf::Font, std::string> m_fonts;

    TestEntity m_ent;
};
