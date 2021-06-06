#pragma once
#include "Scene.h"

class UICommand
{
public:
	UICommand();
	virtual ~UICommand();

	virtual void execute(sf::RenderWindow* window) = 0;
};

