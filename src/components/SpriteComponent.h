// SpriteComponent.h
#pragma once

#include "Component.h"
#include "SFML/Graphics/Sprite.hpp"

struct SpriteComponent : public Component
{
    sf::Sprite sprite;
};