#include "UIGotoMenu.h"

UIGotoMenu::UIGotoMenu(std::stack<Scene*>* scenes): scenes(scenes)
{
}

UIGotoMenu::~UIGotoMenu()
{
}

void UIGotoMenu::execute(sf::RenderWindow* window)
{
	auto* currentScene = this->scenes->top();
	this->scenes->pop();
	this->scenes->push(new MenuScene(window, this->scenes));
	delete currentScene;
}
