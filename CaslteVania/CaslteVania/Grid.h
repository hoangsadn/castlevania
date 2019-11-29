#pragma once
#include "Cell.h"
#define loop(x,k,n) for(int x = k; x <= n; ++x)
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
	void RemoveObject(CGameObject & obj);
	void RemoveStaticObject(CGameObject & obj);
	void AddObject(CGameObject * obj);
	void UpdateObject(CGameObject & obj, int posX, int posY);
	void CreateFileGird(int level);
	void Update();
	
	void UpdatePresentCell();

	std::unordered_set<LPGAMEOBJECT> GetObj();
	std::vector<LPGAMEOBJECT> GetWall();

	void FindCell(RECT r, GAMEOBJECT &obj);
	~Grid();
};
