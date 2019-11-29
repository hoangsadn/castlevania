#include "Grid.h"
#include "Items.h"
#include "HolderCandle.h"
#include "HolderFirePillar.h"
#include "CheckPoint.h"
#include "Weapons.h"
#include "Enemys.h"
#include "Brick.h"
#include "Stair.h"
#include "HolderHiddenBrick.h"
void Grid::FindCell(RECT r, GAMEOBJECT &object)
{
	object.LeftCell = r.left / WidthCell;
	object.TopCell = r.top / HeightCell;
	object.RightCell = r.right / WidthCell;
	object.BottomCell = r.bottom / HeightCell;
}
void Grid::Init()
{
	rows = 15;
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
void Grid::CreateFileGird(int level)
{
	// w map:2816 ,height map : 368 , w cell = 176 , h cell = 92;
	Init();
	ifstream File;
	ofstream wFile;
	
	char gridFileName[30];
	sprintf_s(gridFileName, "text\\obj\\Scene%d_Object.txt", level);
	File.open(gridFileName);

	sprintf_s(gridFileName, "text\\Grid%d.txt", level);
	wFile.open(gridFileName);

	float posX, posY, width, height, id;

	string str, type;

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
			AddObject(holder);
			/*rect = holder->GetRect();
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
			}*/
			break;
		}
		case HIDDEN_BRICK: case HIDDEN_BRICK_SMALL:
		{
			File >> posX >> posY >> type;
			CHolderHiddenBrick * hideBrick = new CHolderHiddenBrick(TYPEString[type]);
			if (TYPEString[str] == HIDDEN_BRICK_SMALL)
				hideBrick->CurAnimation = hideBrick->animations[HIDDEN_BRICK_SMALL];
			hideBrick->SetPosition(posX, posY);
			AddObject(hideBrick);
			rect = hideBrick->GetRect();
			FindCell(rect, *obj);

			for (int r = obj->TopCell; r <= obj->BottomCell; ++r)
			{
				if (r < 0 || r >= rows) continue;
				for (int c = obj->LeftCell; c <= obj->RightCell; ++c)
				{
					if (c < 0 || c >= cols) continue;
					cells[r][c]->CannotTouchObjects.insert(hideBrick);
				}
			}
			break;
		}
		case CHECKPOINT:
		{
			File >> posX >> posY >> id >> type;

			CCheckPoint * checkpoint = new CCheckPoint();
			checkpoint->id = id;
			checkpoint->type = TYPEString[type];
			checkpoint->SetPosition(posX, posY);
			checkpoint->Init();

			AddObject(checkpoint);

			
			break;
		}
		case GHOST:
		{
			File >> posX >> posY;
			auto ghost = CEnemys::CreateEnemy(1);
			ghost->SetPosition(posX, posY);
			ghost->repawnPosX = posX;
			ghost->repawnPosY = posY;
			AddObject(ghost);
		}
		case BLACKPANTHER:
		{
			File >> posX >> posY;
			auto panther = CEnemys::CreateEnemy(2);
			panther->SetPosition(posX, posY);
			panther->repawnPosX = posX;
			panther->repawnPosY = posY;
			AddObject(panther);
			break;
		}
		case BAT:
		{
			File >> posX >> posY;
			auto bat = CEnemys::CreateEnemy(3);
			bat->SetPosition(posX, posY);
			bat->repawnPosX = posX;
			bat->repawnPosY = posY;
			AddObject(bat);
			break;
		}
		case AQUAMAN:
		{
			File >> posX >> posY;
			auto aqua = CEnemys::CreateEnemy(4);
			aqua->SetPosition(posX, posY);
			aqua->repawnPosX = posX;
			aqua->repawnPosY = posY;
			AddObject(aqua);
			break;
		}
		case STAIR:
		{
			File >> posX >> posY >> type;
			auto stair = new CStair(TYPEString[type]);
			stair->SetPosition(posX, posY);
			AddObject(stair);
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
				g->selected = true;
				Objlist.insert(g);
				
				
			}
		}
	}

	//unselect obj
	for (auto c : PresentCell)
		for (auto g : c->objects)
		{
			g->selected = false;
		}
	
	GAMELOG("sl ob %d", Objlist.size());
	return Objlist;
}
std::vector<LPGAMEOBJECT> Grid::GetWall()
{
	std::vector<LPGAMEOBJECT> Objlist;
	for (auto c : PresentCell)
	{
		for (auto g : c->CannotTouchObjects)
		{
			if (!g->selected)
			{
				g->selected = true;
				Objlist.push_back(g);
			}
		}
	}

	//unselect obj
	for (auto c : PresentCell)
		for (auto g : c->CannotTouchObjects)
			g->selected = false;

	//	GAMELOG("sl ob %d", Objlist.size());

	return Objlist;
}
void Grid::UpdateObject(CGameObject & obj, int posX, int posY)
{
	auto oldObj = new GAMEOBJECT();
	oldObj->LeftCell = posX / WidthCell;
	oldObj->TopCell = posY / HeightCell;
	oldObj->RightCell = (posX +obj.width) / WidthCell;
	oldObj->BottomCell = (posY + obj.height) / HeightCell;

	auto newObj = new GAMEOBJECT();
	FindCell(obj.GetRect(), *newObj);
	
	//GAMELOG("MOVE");
	if (oldObj->LeftCell != newObj->LeftCell || oldObj->TopCell != newObj->TopCell|| oldObj->RightCell != newObj->RightCell || oldObj->BottomCell != newObj->BottomCell)
	{
		//GAMELOG("CHANGE");
	//	GAMELOG("old pos %d %d %d %d", oldObj->LeftCell, oldObj->TopCell, oldObj->RightCell, oldObj->BottomCell);
		//GAMELOG("new pos %d %d %d %d", newObj->LeftCell, newObj->TopCell, newObj->RightCell, newObj->BottomCell);
		//if obj move to the right to left . the newObj in two cells . 
		//if (oldObj->LeftCell != oldObj->RightCell || oldObj->TopCell != oldObj->BottomCell)
		if ((oldObj->RightCell-oldObj->LeftCell+oldObj->BottomCell-oldObj->TopCell)> (newObj->RightCell - newObj->LeftCell + newObj->BottomCell - newObj->TopCell))
		{
			loop(r, oldObj->TopCell, oldObj->BottomCell)
				loop(c, oldObj->LeftCell, oldObj->RightCell)
				cells[r][c]->objects.erase(&obj);

			loop(r, newObj->TopCell, newObj->BottomCell)
				loop(c, newObj->LeftCell, newObj->RightCell)
				cells[r][c]->objects.insert(&obj);

		
			GAMELOG("Xoa 1");
		}
		// the Old obj in two cells
		//else if (newObj->LeftCell != newObj->RightCell || newObj->TopCell != newObj->BottomCell)
		else if ((oldObj->RightCell - oldObj->LeftCell + oldObj->BottomCell - oldObj->TopCell) < (newObj->RightCell - newObj->LeftCell + newObj->BottomCell - newObj->TopCell))
		{
			

			loop(r, newObj->TopCell, newObj->BottomCell)
				loop(c, newObj->LeftCell, newObj->RightCell)
				cells[r][c]->objects.insert(&obj);

			loop(r, oldObj->TopCell, oldObj->BottomCell)
				loop(c, oldObj->LeftCell, oldObj->RightCell)
				cells[r][c]->objects.erase(&obj);
			GAMELOG("Xoa 2");
		}
		else
		{
			loop(r, oldObj->TopCell, oldObj->BottomCell)
				loop(c, oldObj->LeftCell, oldObj->RightCell)
				cells[r][c]->objects.erase(&obj);
			loop(r, newObj->TopCell, newObj->BottomCell)
				loop(c, newObj->LeftCell, newObj->RightCell)
				cells[r][c]->objects.insert(&obj);
			GAMELOG("Xoa 3");
			
		}
		
	}
}
void Grid::AddObject(CGameObject * obj)
{
	auto o = new GAMEOBJECT();
	FindCell(obj->GetRect(), *o);
	loop(r, o->TopCell, o->BottomCell)
		loop(c, o->LeftCell, o->RightCell)
		cells[r][c]->objects.insert(obj);
	GAMELOG("add %d %d %d %d", o->LeftCell, o->TopCell, o->RightCell, o->BottomCell);
}
void Grid::RemoveObject(CGameObject & obj)
{
	auto o = new GAMEOBJECT();
	
	FindCell(obj.GetRect(),*o);
	loop(r, o->TopCell, o->BottomCell)
		loop(c, o->LeftCell, o->RightCell)
			cells[r][c]->objects.erase(&obj);
	GAMELOG("removes %d %d %d %d", o->LeftCell, o->TopCell, o->RightCell, o->BottomCell);
}
void Grid::RemoveStaticObject(CGameObject & obj)
{
	auto o = new GAMEOBJECT();

	FindCell(obj.GetRect(), *o);
	loop(r, o->TopCell, o->BottomCell)
		loop(c, o->LeftCell, o->RightCell)
		cells[r][c]->CannotTouchObjects.erase(&obj);
}
void Grid::UpdatePresentCell()
{
	PresentCell.clear();
	auto obj = new GAMEOBJECT();
	FindCell(cam, *obj);
	loop(r,obj->TopCell,obj->BottomCell)
	{
		//if (r < 0 || r >= rows) continue;
		loop(c, obj->LeftCell, obj->RightCell)
		{
		//	if (c < 0 || c >= cols) continue;
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
