#pragma once
#include "Scene.h"
#include "Button.h"
#include "UIRepeatLevel.h"
#include "UIClose.h"
#include "UIGotoMenu.h"

class GameOverScene :
    public Scene
{
private:
	sf::Font font;
	sf::Text gameOverText;

	std::vector<Button> buttons;
	std::map<std::string, UICommand*> commands;

	void setButtonsPosition();
	float getButtonsHeight();
public:
	GameOverScene(sf::RenderWindow* window, std::stack<Scene*>* scenes);
	virtual ~GameOverScene();
	virtual void update(const float& deltaTime);
	virtual void render(const float& deltaTime);
	virtual void handleEvents(const sf::Event& event);
};

