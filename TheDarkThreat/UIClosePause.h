#pragma once
#include "UICommand.h"
class UIClosePause :
    public UICommand
{
private:
    std::stack<Scene*>* scenes;
public:
    UIClosePause(std::stack<Scene*>* scenes);
    ~UIClosePause();

    void execute(sf::RenderWindow* window);
};

