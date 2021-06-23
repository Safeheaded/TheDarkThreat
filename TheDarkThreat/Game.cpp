#include "Game.h"

Game::Game()
{
	this->initWindow();
    this->sceneManager = new SceneManager(this->window);

    setupMusic();
}

void Game::setupMusic()
{
    this->buffer.loadFromFile("assets\\music\\main_score.wav");
    this->sound.setBuffer(this->buffer);
    this->sound.setLoop(true);
    this->sound.setVolume(5.f);
    this->sound.play();
}

Game::~Game()
{
	delete this->window;  

    delete this->sceneManager;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "The Dark Threat");
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::updateEvents()
{
    while (this->window->pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed)
            this->window->close();

        // Passing event object to scenes
        this->sceneManager->handleEvents(this->event);
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
