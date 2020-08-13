#pragma once

#include <SFML/Graphics.hpp>

class Application
{
public:
    Application();

    void run();

private:
    sf::RenderWindow m_window;
};
