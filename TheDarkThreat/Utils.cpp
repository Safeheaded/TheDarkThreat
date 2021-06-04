#include "Utils.h"

void Utils::loadFont(std::string path, sf::Font* font)
{
	if (!font->loadFromFile(path)) {
		throw "Couldn\'t load font";
	}
}
