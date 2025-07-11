// RenderSystem.cpp
#include "RenderSystem.h"

void RenderSystem::Update(const std::vector<std::unique_ptr<GameObject>> &gameObjects, sf::RenderWindow &gameWindow)
{
    for (auto &obj : gameObjects)
    {
        if (auto sprite = obj->GetComponent<SpriteComponent>())
        {
            if (auto transform = obj->GetComponent<TransformComponent>())
            {
                sf::Vector2f transformPosition = transform->GetVec2f();
                sprite->sprite.setPosition(transformPosition);
                gameWindow.draw(sprite->sprite);
            }
        }
    }
}