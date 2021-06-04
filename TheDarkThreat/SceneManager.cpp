#include "SceneManager.h"
#include "MenuScene.h"

void SceneManager::initScenes()
{
    this->scenes.push(new MenuScene(this->window, &this->scenes));
}

SceneManager::SceneManager(sf::RenderWindow* window): window(window)
{
    this->initScenes();
}

SceneManager::~SceneManager()
{
    while (!this->scenes.empty()) {
        delete this->scenes.top();
        this->scenes.pop();
    }
}

void SceneManager::render(const float& deltaTime)
{
    if (!this->scenes.empty()) {
        this->scenes.top()->render(deltaTime);
    }
}

void SceneManager::update(const float& deltaTime)
{
    if (!this->scenes.empty()) {
        this->scenes.top()->update(deltaTime);
    }
}

void SceneManager::handleEvents(const sf::Event& event)
{
    if (!this->scenes.empty()) {
        this->scenes.top()->handleEvents(event);
    }
}
