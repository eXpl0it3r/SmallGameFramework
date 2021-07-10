#pragma once

#include "State/State.hpp"
#include "Entity/Explosion.hpp"

struct Resources;

class PlayState final : public State
{
public:
    explicit PlayState(sf::RenderWindow& window, Resources& resources);

private:
    void processEvents() override;
    void update(sf::Time delta_time) override;
    void render() override;

    Explosion m_explosion;
};
