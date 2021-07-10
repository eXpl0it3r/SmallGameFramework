#pragma once

#include "Entity/Button.hpp"
#include "State/State.hpp"

struct Resources;

class MenuState final : public State
{
public:
    explicit MenuState(sf::RenderWindow& window, Resources& resources);

private:
    void processEvents() override;
    void update(sf::Time delta_time) override;
    void render() override;

    void handleButtonMouseInteraction(Button& button) const;

    sf::Vector2f m_current_mouse_position;
    bool m_mouse_button_released;

    Button m_start;
    Button m_options;
    Button m_exit;
};
