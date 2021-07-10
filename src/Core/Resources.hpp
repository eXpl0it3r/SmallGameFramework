#pragma once

#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>

const auto FontSpaceGrotesk = std::string{ "SpaceGrotesk" };

struct Resources
{
    thor::ResourceHolder<sf::Texture, std::string> Textures;
    thor::ResourceHolder<sf::Font, std::string> Fonts;
};
