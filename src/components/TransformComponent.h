// TransformComponent.h
#pragma once

#include "Component.h"
#include "SFML/System/Angle.hpp"
#include "SFML/System/Vector2.hpp"

struct TransformComponent : public Component
{
    TransformComponent() = default;
    TransformComponent(float x, float y) : x(x), y(y) {}
    float x, y;
    sf::Angle rotation;
    sf::Vector2f GetVec2f() { return sf::Vector2f(x, y); }
};