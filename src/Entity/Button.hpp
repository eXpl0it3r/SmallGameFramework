#pragma once

#include "Entity/Entity.hpp"
#pragma once

struct Resources;

class Button final : public Entity
{
public:
    Button(const std::string& text, const Resources& resources);

    void update(sf::Time delta_time) override;
    sf::FloatRect globalBounds() const;

    void mouseOver();
    void mouseLeave();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Text m_text;
};
