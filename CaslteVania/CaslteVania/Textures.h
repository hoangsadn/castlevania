#pragma once
#include <unordered_map>
#include "debug.h"
#include "GlobalConfig.h"
#include "Game.h"
using namespace std;

/*
	Manage texture database
*/
class CTextures
{
	static CTextures * __instance;

	unordered_map<int, LPDIRECT3DTEXTURE9> textures;

public:
	CTextures();
	
	void Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor);
	void LoadResources();
	LPDIRECT3DTEXTURE9 Get(unsigned int i);

	static CTextures * GetInstance();
};
