#include "Animation.hpp"

#include "json.hpp"

#include <fstream>

Animation::Animation(const std::string& filename)
: m_animator{m_map}
{
    parse(filename);
}

// TODO: Missing error handling regarding JSON
void Animation::parse(const std::string& filename)
{
    nlohmann::json animations;

    std::fstream file(filename, std::ios::in | std::ios::binary);

    if(!file.is_open())
        throw(std::runtime_error{"Failed to open animation file \"" + filename + "\"."});

    try
    {
        file >> animations;
    }
    catch(std::exception& e)
    {
        throw(std::runtime_error{"The animation file \"" + filename + "\" contains invalid JSON data."});
    }

    for(auto animation = animations.begin(); animation != animations.end(); ++animation)
    {
        m_animations.emplace_back();

        for(auto& frame : animation.value()["frames"])
            m_animations.back().addFrame(frame[0], {frame[1], frame[2], frame[3], frame[4]});

        m_map.addAnimation(animation.key(), m_animations.back(), sf::seconds(animation.value()["duration"]));
    }
}

thor::Animator<sf::Sprite, std::string>& Animation::animator()
{
    return m_animator;
}
