#pragma once
#include "Scene.h"
#include "Button.h"
#include "UIClose.h"
#include "Utils.h"
#include "TextButton.h"
#include "UINextScene.h"
#include "PlotScene.h"

class MenuScene :
    public Scene
{
private:
    std::vector<Button> buttons;
    std::map<std::string, UICommand*> commands;
    sf::Font font;
    int savedLevel;

    // Methods
    void setupButtons();
    void setButtonsPosition();
    float getButtonsHeight();
    void setupCommands();
public:
    MenuScene(sf::RenderWindow* window, std::stack<Scene*>* scenes);
    ~MenuScene();

    void update(const float& deltaTime);
    void render(const float& deltaTime);
    void handleEvents(const sf::Event& event);
};

