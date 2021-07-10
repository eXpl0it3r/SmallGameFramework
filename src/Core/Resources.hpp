#pragma once

#include <SFML/Graphics.hpp>
#include <Thor/Resources.hpp>

namespace Font
{
const auto SpaceGrotesk = std::string{ "SpaceGrotesk" };
}

namespace Texture
{
const auto Explosion = std::string{ "Explosion" };
}

struct Resources
{
    thor::ResourceHolder<sf::Texture, std::string> Textures;
    thor::ResourceHolder<sf::Font, std::string> Fonts;
};
