#include "Entity/Button.hpp"

#include <cmath>

#include "Core/Resources.hpp"

Button::Button(const std::string& text, const Resources& resources)
    : m_text{ text, resources.Fonts[Font::SpaceGrotesk], 80 }
{
    m_text.setFillColor(sf::Color{ 0xDDDDDDFF });
    m_text.setOrigin(m_text.getLocalBounds().getSize() / 2.f + m_text.getLocalBounds().getPosition());
    m_text.setOrigin({ std::round(m_text.getOrigin().x), std::round(m_text.getOrigin().y) });
}

void Button::update(sf::Time delta_time)
{
}

sf::FloatRect Button::globalBounds() const
{
    return getTransform().transformRect(m_text.getGlobalBounds());
}

void Button::mouseOver()
{
    m_text.setOutlineColor(sf::Color{ 0xDDDDDDFF });
    m_text.setOutlineThickness(1.f);
    m_text.setOutlineColor(sf::Color{ 0xAAAAAAFF });
}

void Button::mouseLeave()
{
    m_text.setFillColor(sf::Color{ 0xFFFFFFFF });
    m_text.setOutlineThickness(0.f);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_text, states);
}
