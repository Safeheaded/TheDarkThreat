#pragma once
#include "Scene.h"
#include "Button.h"
#include "UIClose.h"
#include "Utils.h"
#include "TextButton.h"
class MenuScene :
    public Scene
{
private:
    std::vector<Button> buttons;
    UIClose* uiClose;
    sf::Font font;

    // Methods
    void setupButtons();
    void setButtonsPosition();
    float getButtonsHeight();
public:
    MenuScene(sf::RenderWindow* window, std::stack<Scene*>* scenes);
    ~MenuScene();

    void update(const float& deltaTime);
    void render(const float& deltaTime);
    void handleEvents(const sf::Event& event);
};

