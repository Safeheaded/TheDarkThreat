#pragma once
#include <vector>

class Map
{
public:
	static std::vector<std::vector<int>> getOverworldMap();
	static std::vector<std::vector<int>> getUnderworldMap();
};

