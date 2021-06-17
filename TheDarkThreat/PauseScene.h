#pragma once
#include "Scene.h"
#include "Button.h"
#include "UIGotoMenu.h"
#include "Button.h"
#include "UIClosePause.h"
#include "UIClose.h"

class PauseScene :
    public Scene
{
private:
    sf::Text text;
    sf::Font font;
    std::vector<Button> buttons;
    std::map<std::string, UICommand*> commands;

    void setButtonsPosition();
    float getButtonsHeight();
public:
    PauseScene(sf::RenderWindow* window, std::stack<Scene*>* scenes);
    ~PauseScene();

    virtual void update(const float& deltaTime);
    virtual void render(const float& deltaTime);
    virtual void handleEvents(const sf::Event& event);
};

