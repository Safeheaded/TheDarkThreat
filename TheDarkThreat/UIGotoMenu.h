#pragma once
#include "UICommand.h"
#include "MenuScene.h"
class UIGotoMenu :
    public UICommand
{
private:
    std::stack<Scene*>* scenes;
public:
    UIGotoMenu(std::stack<Scene*>* scenes);
    ~UIGotoMenu();

    void execute(sf::RenderWindow* window);
};

