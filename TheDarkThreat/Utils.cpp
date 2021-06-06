#include "Utils.h"

void Utils::loadFont(std::string path, sf::Font* font)
{
	if (!font->loadFromFile(path)) {
		throw "Couldn\'t load font";
	}
}

std::string Utils::loadFullText(std::string path)
{
	std::ifstream t(path);
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	return str;
}
