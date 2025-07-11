// TransformComponent.h
#pragma once

#include "Component.h"
#include "SFML/System/Angle.hpp"

struct TransformComponent : public Component
{
    float x, y;
    sf::Angle rotation;
};