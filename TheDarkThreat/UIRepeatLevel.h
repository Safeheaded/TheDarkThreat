#pragma once
#include "UICommand.h"
#include "Level1.h"

class UIRepeatLevel :
    public UICommand
{
private:
    std::stack<Scene*>* scenes;
public:
    UIRepeatLevel(std::stack<Scene*>* scenes);
    ~UIRepeatLevel();
    void execute(sf::RenderWindow* window);
};

