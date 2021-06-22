#pragma once
#include "Scene.h"
#include "Level1.h"
#include <functional>

class PlotScene :
    public Scene
{
private:
    sf::Text text;
    sf::Text instructionText;
    sf::Font font;

    std::function<void()> fun;

    void setupText(const std::string& text);
public:
    PlotScene(sf::RenderWindow* window, std::stack<Scene*>* scenes, 
        std::string text, std::function<void()> fun);
    ~PlotScene();

    void update(const float& deltaTime);
    void render(const float& deltaTime);
    void handleEvents(const sf::Event& event);
};

