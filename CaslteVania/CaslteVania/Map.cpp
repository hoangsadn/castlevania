#include "Map.h"

Map * Map::_instance = NULL;

Map::Map()
{
	ifstream File;
	File.open(L"textures\\map.txt");
	File >> col >> row;
	mapTiles = new int*[row];
	for (int r = 1; r <= row; ++r)
	{
		mapTiles[r] = new int[col];
		for (int c = 1; c <= col; ++c)
		{
			File >> mapTiles[r][c];
		}
	}

	File.close();
}

void Map::Render()
{
	CTextures * textures = CTextures::GetInstance();
	LPDIRECT3DTEXTURE9 texMap = textures->Get(ID_TEX_TITLE);
	CSprites * sprites = CSprites::GetInstance();
	sprites->Add(99999, 0,0, 32,1568, texMap);
	CSprite* sprite = sprites->Get(99999);
	for (int i = 1; i <= row; ++i)
		for (int j = 1; j <= col; ++j)
		{
			if (mapTiles[i][j] == 0)
			{
				sprite->Draw(i * 32, j * 32, 0, 0, 32, 32);
			}
			else sprite->Draw(j * 32, i* 32, 32 * mapTiles[i][j]-32, 0, 32*mapTiles[i][j] , 32);

		}

}
Map * Map::GetInstance()
{
	if (_instance == NULL)
		_instance = new Map();
	return _instance;
}
Map::~Map()
{
}
