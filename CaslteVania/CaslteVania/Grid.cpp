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
	ifstream GridFile;

	char gridFileName[30];

	sprintf_s(gridFileName, "text\\Grid%d.txt", level);
	GridFile.open(gridFileName);
	float posX, posY, width, height, id;
	int left, top, right, bot;
	string str, type;
	GridFile >> WidthCell >> HeightCell >> rows >> cols;
	Init();

	while (!GridFile.eof())
	{
		auto obj = new GAMEOBJECT();
		RECT rect;
		GridFile >> str;		// read type of obj
		switch (TYPEString[str])
		{
		case FIRE_PILLAR:
		{
			GridFile >> posX >> posY >> width >> height >> str;
			GridFile >> left >> top >> right >> bot;

			CHolderFirePillar * holder = new CHolderFirePillar(TYPEString[str]);
			holder->SetPosition(posX, posY);
			holder->width = width;
			holder->height = height;

			loop(r, top, bot)
				loop(c, left, right)
				cells[r][c]->objects.insert(holder);


			break;
		}
		case BRICK:
		{
			GridFile >> posX >> posY >> width >> height;
			GridFile >> left >> top >> right >> bot;
			CBrick * brick = new CBrick();
			brick->SetPosition(posX, posY);
			brick->SetWidthHeight(width, height);

			for (int r = top; r <= bot; ++r)
			{
				if (r < 0 || r >= rows) continue;
				for (int c = left; c <= right; ++c)
				{
					if (c < 0 || c >= cols) continue;
					cells[r][c]->CannotTouchObjects.insert(brick);
				}
			}
			break;
		}
		case CANDLE:
		{
			GridFile >> posX >> posY >> width >> height >> str;
			GridFile >> left >> top >> right >> bot;
			CHolderCandle * holder = new CHolderCandle(TYPEString[str]);
			holder->SetPosition(posX, posY);
			holder->width = width;
			holder->height = height;

			loop(r, top, bot)
				loop(c, left, right)
				cells[r][c]->objects.insert(holder);

			break;
		}
		case HIDDEN_BRICK: case HIDDEN_BRICK_SMALL:
		{
			GridFile >> posX >> posY >> width >> height >> type;
			GridFile >> left >> top >> right >> bot;
			CHolderHiddenBrick * hideBrick = new CHolderHiddenBrick(TYPEString[type]);
			if (TYPEString[str] == HIDDEN_BRICK_SMALL)
				hideBrick->CurAnimation = hideBrick->animations[HIDDEN_BRICK_SMALL];
			hideBrick->SetPosition(posX, posY);
			hideBrick->width = width;
			hideBrick->height = height;

			loop(r, top, bot)
				loop(c, left, right)
				cells[r][c]->objects.insert(hideBrick);

			loop(r, top, bot)
				loop(c, left, right)
				cells[r][c]->CannotTouchObjects.insert(hideBrick);
			break;
		}
		case CHECKPOINT:
		{
			GridFile >> posX >> posY >> id >> width >> height >> type;
			GridFile >> left >> top >> right >> bot;
			CCheckPoint * checkpoint = new CCheckPoint();
			checkpoint->id = id;
			checkpoint->type = TYPEString[type];
			checkpoint->width = width;
			checkpoint->height = height;
			checkpoint->SetPosition(posX, posY);
			checkpoint->Init();

			loop(r, top, bot)
				loop(c, left, right)
				cells[r][c]->objects.insert(checkpoint);

			break;
		}
		case GHOST:
		{
			GridFile >> posX >> posY >> width >> height;
			GridFile >> left >> top >> right >> bot;
			auto ghost = CEnemys::CreateEnemy(1);
			ghost->SetPosition(posX, posY);
			ghost->width = width;
			ghost->height = height;
			ghost->repawnPosX = posX;
			ghost->repawnPosY = posY;
			loop(r, top, bot)
				loop(c, left, right)
				cells[r][c]->objects.insert(ghost);
			break;
		}
		case BLACKPANTHER:
		{
			GridFile >> posX >> posY >> width >> height;
			GridFile >> left >> top >> right >> bot;
			auto panther = CEnemys::CreateEnemy(2);
			panther->SetPosition(posX, posY);
			panther->width = width;
			panther->height = height;
			panther->repawnPosX = posX;
			panther->repawnPosY = posY;

			loop(r, top, bot)
				loop(c, left, right)
				cells[r][c]->objects.insert(panther);

			break;
		}
		case BAT:
		{
			GridFile >> posX >> posY >> width >> height;
			GridFile >> left >> top >> right >> bot;
			auto bat = CEnemys::CreateEnemy(3);
			bat->SetPosition(posX, posY);
			bat->width = width;
			bat->height = height;
			bat->repawnPosX = posX;
			bat->repawnPosY = posY;

			loop(r, top, bot)
				loop(c, left, right)
				cells[r][c]->objects.insert(bat);
			break;
		}
		case AQUAMAN:
		{
			GridFile >> posX >> posY >> width >> height;
			GridFile >> left >> top >> right >> bot;
			auto aqua = CEnemys::CreateEnemy(4);
			aqua->SetPosition(posX, posY);
			aqua->width = width;
			aqua->height = height;
			aqua->repawnPosX = posX;
			aqua->repawnPosY = posY;

			loop(r, top, bot)
				loop(c, left, right)
				cells[r][c]->objects.insert(aqua);

			break;
		}
		case STAIR:
		{
			GridFile >> posX >> posY >> width >> height >> type;
			GridFile >> left >> top >> right >> bot;
			auto stair = new CStair(TYPEString[type]);
			stair->SetPosition(posX, posY);
			stair->width = width;
			stair->height = height;

			loop(r, top, bot)
				loop(c, left, right)
				cells[r][c]->objects.insert(stair);
			break;
		}
		}


	}

	GridFile.close();

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
	oldObj->RightCell = (posX + obj.width) / WidthCell;
	oldObj->BottomCell = (posY + obj.height) / HeightCell;

	auto newObj = new GAMEOBJECT();
	FindCell(obj.GetRect(), *newObj);

	//calc number of cell new and old . 
	if (oldObj->LeftCell != newObj->LeftCell || oldObj->TopCell != newObj->TopCell || oldObj->RightCell != newObj->RightCell || oldObj->BottomCell != newObj->BottomCell)
	{
		
		//GAMELOG("old pos %d %d %d %d", oldObj->LeftCell, oldObj->TopCell, oldObj->RightCell, oldObj->BottomCell);
		//GAMELOG("new pos %d %d %d %d", newObj->LeftCell, newObj->TopCell, newObj->RightCell, newObj->BottomCell);

		
		if ((oldObj->RightCell - oldObj->LeftCell + oldObj->BottomCell - oldObj->TopCell) > (newObj->RightCell - newObj->LeftCell + newObj->BottomCell - newObj->TopCell))
		{
			loop(r, oldObj->TopCell, oldObj->BottomCell)
				loop(c, oldObj->LeftCell, oldObj->RightCell)
				cells[r][c]->objects.erase(&obj);

			loop(r, newObj->TopCell, newObj->BottomCell)
				loop(c, newObj->LeftCell, newObj->RightCell)
				cells[r][c]->objects.insert(&obj);


			//GAMELOG("Xoa 1");
		}
	
		else if ((oldObj->RightCell - oldObj->LeftCell + oldObj->BottomCell - oldObj->TopCell) < (newObj->RightCell - newObj->LeftCell + newObj->BottomCell - newObj->TopCell))
		{


			loop(r, newObj->TopCell, newObj->BottomCell)
				loop(c, newObj->LeftCell, newObj->RightCell)
				cells[r][c]->objects.insert(&obj);

			loop(r, oldObj->TopCell, oldObj->BottomCell)
				loop(c, oldObj->LeftCell, oldObj->RightCell)
				cells[r][c]->objects.erase(&obj);
			//GAMELOG("Xoa 2");
		}
		else
		{
			//
			loop(r, oldObj->TopCell, oldObj->BottomCell)
				loop(c, oldObj->LeftCell, oldObj->RightCell)
				cells[r][c]->objects.erase(&obj);
			loop(r, newObj->TopCell, newObj->BottomCell)
				loop(c, newObj->LeftCell, newObj->RightCell)
				cells[r][c]->objects.insert(&obj);
			//GAMELOG("Xoa 3");

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

	FindCell(obj.GetRect(), *o);
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
	loop(r, obj->TopCell, obj->BottomCell)
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
