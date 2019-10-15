#pragma once
#include "GlobalConfig.h"
#include "Sprites.h"
#include <fstream>
class Map
{
private:
	static Map* _instance;
	int col;
	int row;
	int** mapTiles;

public:
	Map();
	~Map();
	void Render();
	static Map* GetInstance();
};

