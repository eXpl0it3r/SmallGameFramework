#pragma once

#include "State/State.hpp"
#include "Entity/TestEntity.hpp"

struct Resources;

class TestState final : public State
{
public:
    explicit TestState(sf::RenderWindow& window, Resources& resources);

private:
    void processEvents() override;
    void update(sf::Time delta_time) override;
    void render() override;

    void loadResources() const;

    TestEntity m_ent;
};
