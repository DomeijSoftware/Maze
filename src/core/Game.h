// Game.h
#pragma once

#include "SFML/Graphics.hpp"

#include <vector>

#include "GameObject.h"

class Game
{
public:
    Game();
    ~Game();
    void Run();

private:
    const sf::Vector2u GAMEWINDOWSIZE;
    sf::RenderWindow gameWindow;
    std::vector<GameObject> gameObjects;
};