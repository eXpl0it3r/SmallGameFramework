#pragma once

#include <Thor/Animations.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class Animation
{
public:
    explicit Animation(const std::string& filename);

    thor::Animator<sf::Sprite, std::string>& animator();

protected:
    thor::Animator<sf::Sprite, std::string> m_animator;

private:
    void parse(const std::string& filename);

    thor::AnimationMap<sf::Sprite, std::string> m_map;
    std::vector<thor::FrameAnimation> m_animations;
};
