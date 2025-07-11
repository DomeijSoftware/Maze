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