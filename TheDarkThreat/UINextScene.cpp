#include "UINextScene.h"
#include "PlotScene.h"

UINextScene::UINextScene(std::stack<Scene*>* scenes, Scene* scene, Scene* nextScene):
	scenes(scenes), currentScene(scene), nextScene(nextScene)
{
}

UINextScene::~UINextScene()
{
}

void UINextScene::execute(sf::RenderWindow* window)
{
	Scene* currentScene = this->scenes->top();

	//std::string text = Utils::loadFullText("plot1.txt");
	this->scenes->pop();
	this->scenes->push(this->nextScene);

	delete currentScene;
}
