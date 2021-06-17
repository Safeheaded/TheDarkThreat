#include "UIClosePause.h"

UIClosePause::UIClosePause(std::stack<Scene*>* scenes): scenes(scenes)
{
}

UIClosePause::~UIClosePause()
{
}

void UIClosePause::execute(sf::RenderWindow* window)
{
	auto* currentScene = this->scenes->top();
	this->scenes->pop();
	delete currentScene;
}
