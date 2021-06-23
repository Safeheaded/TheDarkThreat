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

	int savedLevel = Utils::getSavedLevel();
	if (savedLevel == 1) {
		this->scenes->push(new Level1(window, this->scenes));
	}
	else if (savedLevel == 2) {
		this->scenes->push(new Level2(window, this->scenes));
	}
}
