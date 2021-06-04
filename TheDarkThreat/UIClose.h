#pragma once
#include "UICommand.h"

class UIClose:
	public UICommand
{
public:
	void execute(sf::RenderWindow* window);
};

