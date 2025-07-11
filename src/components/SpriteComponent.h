// SpriteComponent.h
#pragma once

#include "Component.h"
#include "SFML/Graphics/Sprite.hpp"

struct SpriteComponent : public Component
{
    SpriteComponent() = default;
    SpriteComponent(sf::Sprite s) : sprite(s) {}
    sf::Sprite sprite;
};