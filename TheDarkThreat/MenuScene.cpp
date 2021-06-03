#include "MenuScene.h"

MenuScene::MenuScene(sf::RenderWindow* window, std::stack<Scene*>* scenes):
	Scene(window, scenes)
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::update(const float& deltaTime)
{
	std::cout << "Menu !!!" << std::endl;
}

void MenuScene::render(const float& deltaTime)
{
}
