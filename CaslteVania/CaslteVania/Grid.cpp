#include "Grid.h"
#include "Items.h"
#include "HolderCandle.h"
#include "HolderFirePillar.h"
#include "Weapons.h"
#include "Enemys.h"
#include "Brick.h"
void Grid::FindCell(RECT r, GAMEOBJECT &object)
{
	object.LeftCell = r.left / WidthCell;
	object.TopCell = r.top / HeightCell;
	object.RightCell = r.right / WidthCell;
	object.BottomCell = r.bottom / HeightCell;
}
void Grid::Init()
{
	rows = 8;
	cols = 32;
	HeightCell = 92;
	WidthCell = 176;

	/*for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cells[i][j]->objects.clear();*/
	cells.clear();
	for (int y = 0; y < rows; ++y)
	{
		auto row = std::vector<Cell*>();
		for (int x = 0; x < cols; ++x)
		{
			row.push_back(new Cell(x, y));
		}
		cells.push_back(row);
	}
	
}
void Grid::CreateFileGird(LPCWSTR filePath)
{
	// w map:2816 ,height map : 368 , w cell = 176 , h cell = 92;
	Init();
	ifstream File;
	ofstream wFile;

	File.open(filePath);
	wFile.open(L"text\\Grid.txt");
	float posX, posY, width, height;
	string str;

	while (!File.eof())
	{
		auto obj = new GAMEOBJECT();
		RECT rect;
		File >> str;		// read type of obj
		wFile << str <<"\n";
		switch (TYPEString[str])
		{
		case FIRE_PILLAR:
		{
			File >> posX >> posY >> str;
			CHolderFirePillar * holder = new CHolderFirePillar(TYPEString[str]);
			holder->SetPosition(posX, posY);
			rect = holder->GetRect();
			FindCell(rect, *obj);
			wFile << obj->LeftCell <<" "<< obj->TopCell <<" "<< obj->RightCell <<" " << obj->BottomCell << "\n";
			for (int r = obj->TopCell; r <= obj->BottomCell; ++r)
			{
				if (r < 0 || r >= rows) continue;
				for (int c = obj->LeftCell; c <= obj->RightCell; ++c)
				{
					if (c < 0 || c >= cols) continue;
					cells[r][c]->objects.insert(holder);
				}
			}
			break;
		}
		case BRICK:
		{
			File >> posX >> posY >> width >> height;
			CBrick * brick = new CBrick();
			brick->SetPosition(posX, posY);
			brick->SetWidthHeight(width, height);
			rect = brick->GetRect();
			FindCell(rect, *obj);
			wFile << obj->LeftCell << " " << obj->TopCell << " " << obj->RightCell << " " << obj->BottomCell << "\n";
			for (int r = obj->TopCell; r <= obj->BottomCell; ++r)
			{
				if (r < 0 || r >= rows) continue;
				for (int c = obj->LeftCell; c <= obj->RightCell; ++c)
				{
					if (c < 0 || c >= cols) continue;
					cells[r][c]->CannotTouchObjects.insert(brick);
				}
			}
			break;
		}
		case CANDLE:
		{
			File >> posX >> posY >> str;
			CHolderCandle * holder = new CHolderCandle(TYPEString[str]);
			holder->SetPosition(posX, posY);
			rect = holder->GetRect();
			FindCell(rect, *obj);
			wFile << obj->LeftCell << " " << obj->TopCell << " " << obj->RightCell << " " << obj->BottomCell << "\n";
			for (int r = obj->TopCell; r <= obj->BottomCell; ++r)
			{
				if (r < 0 || r >= rows) continue;
				for (int c = obj->LeftCell; c <= obj->RightCell; ++c)
				{
					if (c < 0 || c >= cols) continue;
					cells[r][c]->objects.insert(holder);
				}
			}
			break;
		}
		}
	}
	File.close();
	wFile.close();

}

void Grid::Update()
{
	cam = CAMERA->GetBound();
	UpdatePresentCell();
}
std::unordered_set<LPGAMEOBJECT> Grid::GetObj()
{
	std::unordered_set<LPGAMEOBJECT> Objlist;
	for (auto c : PresentCell)
	{
		for (auto g : c->objects)
		{
			if (!g->selected)
			{
				//g->selected = true;
				Objlist.insert(g);
			}
		}
	}
	return Objlist;
}
void Grid::UpdatePresentCell()
{
	PresentCell.clear();
	auto obj = new GAMEOBJECT();
	FindCell(cam, *obj);
	for (int r =obj->TopCell; r <= obj->BottomCell; ++r)
	{
		if (r < 0 || r >= rows) continue;
		for (int c = obj->LeftCell; c <= obj->RightCell; ++c)
		{
			if (c < 0 || c >= cols) continue;
			PresentCell.push_back(cells[r][c]);
		}
	}
}
Grid::Grid()
{
}


Grid::~Grid()
{
}