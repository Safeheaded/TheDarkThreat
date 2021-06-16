#include "SceneManager.h"
#include "MenuScene.h"
#include "PlotScene.h"
#include "Level1.h"

void SceneManager::initScenes()
{
    /*std::string text = Utils::loadFullText("plot1.txt");
    this->scenes.push(new PlotScene(this->window, &this->scenes, text));*/
    this->scenes.push(new MenuScene(this->window, &this->scenes));
    //this->scenes.push(new Level1(this->window, &this->scenes));
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
