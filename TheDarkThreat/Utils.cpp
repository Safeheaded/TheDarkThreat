#include "Utils.h"

void Utils::loadFont(std::string path, sf::Font* font)
{
	if (!font->loadFromFile(path)) {
		throw "Couldn\'t load font";
	}
}

void Utils::loadTexture(std::string path, sf::Texture* texture)
{
	if (!texture->loadFromFile(path)) {
		throw "Could\'nt load texture";
	}
}

std::string Utils::loadFullText(std::string path)
{
	std::ifstream t(path);
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	return str;
}

float Utils::getVectorLength(const sf::Vector2f& v)
{
	return sqrt(pow(v.x, 2)+pow(v.y, 2));
}

sf::Vector2f Utils::normalizeVector(sf::Vector2f v)
{
	auto length = static_cast<float>(sqrt(pow(v.x, 2) + pow(v.y, 2)));
	return v / length;
}

int Utils::getSavedLevel()
{
	try {
		std::ifstream t("saves.txt");
		std::string str((std::istreambuf_iterator<char>(t)),
			std::istreambuf_iterator<char>());

		return std::stoi(str);
	}
	catch (const std::exception& e) {
		return 0;
	}
}

bool Utils::saveLevel(const int& levelNumber)
{
	try {
		std::ofstream myfile;
		myfile.open("saves.txt", std::ios::trunc);
		myfile << levelNumber;
		myfile.close();
	}
	catch (const std::exception& e) {
		return false;
	}
	return true;
}
