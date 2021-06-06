#pragma once
#include "Scene.h"
class PlotScene :
    public Scene
{
private:
    sf::Text text;
    sf::Text instructionText;
    sf::Font font;

    void setupText(const std::string& text);
public:
    PlotScene(sf::RenderWindow* window, std::stack<Scene*>* scenes, const std::string& text);
    ~PlotScene();

    void update(const float& deltaTime);
    void render(const float& deltaTime);
    void handleEvents(const sf::Event& event);
};

