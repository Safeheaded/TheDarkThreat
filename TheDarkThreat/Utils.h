#pragma once
#include "Scene.h"

#include <fstream>
#include <sstream>

class Utils
{
public:
	static void loadFont(std::string path, sf::Font* font);
	static void loadTexture(std::string path, sf::Texture* texture);
	static std::string loadFullText(std::string path);
};

