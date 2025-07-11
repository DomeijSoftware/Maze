#include "Game.h"

Game::Game() : GAMEWINDOWSIZE(800, 600), gameWindow(sf::VideoMode(GAMEWINDOWSIZE), "Game window")
{
    gameWindow.setFramerateLimit(60);
}

Game::~Game()
{
}

void Game::Run()
{
    while (gameWindow.isOpen())
    {
        while (const std::optional event = gameWindow.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                gameWindow.close();
            }
        }

        gameWindow.clear();

        gameWindow.display();
    }
}

void Game::Init()
{
    GameObject obj;
    obj.AddComponent(std::make_unique<TransformComponent>());
    obj.AddComponent(std::make_unique<SpriteComponent>());

    if (auto tf = obj.GetComponent<TransformComponent>())
    {
        tf->x = 100;
        tf->y = 200;
        std::cout << "Position: " << tf->x << ", " << tf->y << std::endl;
    }
}
