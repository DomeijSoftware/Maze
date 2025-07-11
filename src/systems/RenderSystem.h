// RenderSystem.h
#pragma once

#include <vector>
#include <memory>

#include "SFML/Graphics/RenderWindow.hpp"
#include "GameObject.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"

class RenderSystem
{
public:
    void Update(const std::vector<std::unique_ptr<GameObject>> &GameObjects, sf::RenderWindow &gameWindow);
};