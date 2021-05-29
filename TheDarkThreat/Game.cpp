#include "Game.h"

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "The Dark Threat");
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

    // All ellements are being updated below
}

void Game::render()
{
    this->window->clear(sf::Color::Black);

    // All elements are being drawn below

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
