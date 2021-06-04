#pragma once
#include "Scene.h"

class UICommand
{
public:
	UICommand();
	~UICommand();

	virtual void execute(sf::RenderWindow* window) = 0;
};

