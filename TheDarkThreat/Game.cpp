#include "Game.h"

Game::Game()
{
	this->initWindow();
    this->sceneManager = new SceneManager(this->window);
}

Game::~Game()
{
	delete this->window;  

    delete this->sceneManager;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "The Dark Threat");
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::updateEvents()
{
    while (this->window->pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::updateDeltaTime()
{
    this->deltaTime = this->clock.restart().asSeconds();
}

void Game::update()
{
    this->updateEvents();
    this->updateDeltaTime();

    this->sceneManager->update(this->deltaTime);
}

void Game::render()
{
    this->window->clear(sf::Color::Black);

    this->sceneManager->render(this->deltaTime);

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
