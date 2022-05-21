#pragma once

#include <SFML/Graphics.hpp>

#include "Core/ResourceHolder.hpp"

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
    ResourceHolder<sf::Texture, std::string> Textures;
    ResourceHolder<sf::Font, std::string> Fonts;
};
