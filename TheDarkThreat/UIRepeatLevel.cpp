#include "UIRepeatLevel.h"

UIRepeatLevel::UIRepeatLevel(std::stack<Scene*>* scenes): scenes(scenes)
{
}

UIRepeatLevel::~UIRepeatLevel()
{
}

void UIRepeatLevel::execute(sf::RenderWindow* window)
{
	auto* currentScene = this->scenes->top();
	this->scenes->pop();
	this->scenes->push(new Level1(window, this->scenes));
}
