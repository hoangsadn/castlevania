#pragma once
#include "Cell.h"

class Grid
{
	struct GAMEOBJECT
	{
		int TopCell, RightCell, BottomCell, LeftCell;
		TYPE type;
	};
public:
	int rows, cols;
	int HeightCell, WidthCell;
	
	RECT cam;
	Grid();
	std::vector<std::vector<Cell*>> cells;
	std::vector <Cell*> PresentCell;

	void Init();
	
	void CreateFileGird(LPCWSTR filePath);
	void Update();
	
	void UpdatePresentCell();

	std::unordered_set<LPGAMEOBJECT> GetObj();

	void FindCell(RECT r, GAMEOBJECT &obj);
	~Grid();
};
