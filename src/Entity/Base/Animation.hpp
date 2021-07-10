#pragma once

#include <string>
#include <vector>

#include <Thor/Animations.hpp>
#include <SFML/Graphics.hpp>

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
