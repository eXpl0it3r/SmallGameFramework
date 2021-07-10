#pragma once

#include <SFML/Graphics.hpp>

#include "Core/Resources.hpp"

class Application
{
public:
    Application();

    void run();

private:
    void loadCommonResources();

    sf::RenderWindow m_window;
    Resources m_resources;
};
