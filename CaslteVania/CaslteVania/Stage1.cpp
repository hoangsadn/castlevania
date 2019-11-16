#include "Stage1.h"
#include "Whip.h"
#include "Brick.h"
#include "Simon.h"
#include "HolderFirePillar.h"
#include "HolderCandle.h"
#include "Effect.h"
#include "Items.h"
#include "Weapons.h"
#include "CheckPoint.h"
#include "Stair.h"
#include "Enemys.h"
#include "PlayerWalkingState.h"
#include "Grid.h"
Grid * grid;
class CBrick;
vector<LPGAMEOBJECT> CannotTouchObjects;
std::unordered_set<LPGAMEOBJECT> Objlist;


Stage1::Stage1()
{
	camera = camera->GetInstance();
	camera->SetRect(SCREEN_WIDTH, SCREEN_HEIGHT);
	map = map->GetInstance();
	level = 1;
	ChangeMapProc = 0;
	grid = new Grid();
}
void Stage1::LoadObjects(LPCWSTR filePath)
{
	ifstream File;
	File.open(filePath);
	float posX, posY, width, height;
	string str;

	while (!File.eof())
	{
		File >> str;		// read type of obj
		switch (TYPEString[str])
		{
		case FIRE_PILLAR:
		{
			File >> posX >> posY >> str;
			CHolderFirePillar * holder = new CHolderFirePillar(TYPEString[str]);
			holder->SetPosition(posX, posY);
			PresentObjects.insert(holder);
			break;
		}
		case BRICK:
		{
			File >> posX >> posY >> width >> height;
			CBrick * brick = new CBrick();
			brick->SetPosition(posX, posY);
			brick->SetWidthHeight(width, height);
			CannotTouchObjects.push_back(brick);
			break;
		}
		case CANDLE:
		{
			File >> posX >> posY >> str;
			CHolderCandle * holder = new CHolderCandle(TYPEString[str]);
			holder->SetPosition(posX, posY);
			PresentObjects.insert(holder);
			break;
		}
		}
	}
	File.close();

}
void Stage1::LoadResources(int level)
{
	PresentObjects.clear();
	CannotTouchObjects.clear();
	switch (level)
	{
	case 1:
	{
		auto a = new CGlobalConfig();
		a->TypeMapToString();
		CTextures * textures = CTextures::GetInstance();
		textures->LoadResources();
		CSprites * sprites = CSprites::GetInstance();
		sprites->LoadResources();
		CAnimations * animations = CAnimations::GetInstance();
		animations->LoadResources();
		
		camera->map = 2;

		map->LoadResources(L"text\\Level1.txt");
		LoadObjects(L"text\\obj\\Scene1_Object.txt");

		CCheckPoint * checkpoint = new CCheckPoint();
		checkpoint->SetPosition(0.0f, 235.0f);
		PresentObjects.insert(checkpoint);

		
		grid->CreateFileGird(L"text\\obj\\Scene1_Object.txt");
		p = player;
		p->Revival();
		break;

	}
	case 2:
	{
		map->LoadResources(L"text\\Level2.txt");
		//LoadObjects(L"text\\obj\\Scene2_Object.txt");
		p->SetPosition(2900.0f, 0.0f);
		
		CStair * stair = new CStair(STAIR_BOTTOM_RIGHT);
		stair->SetPosition(1220.0f, 315.0f);
		PresentObjects.insert(stair);

		CStair * stair2 = new CStair(STAIR_TOP_LEFT);
		stair2->SetPosition(1347.0f, 72.0f);
		PresentObjects.insert(stair2);


		
		

		/*auto ghost = CEnemys::CreateEnemy(1);
		ghost->SetPosition(1500.0f, 0.0f);
		PresentObjects.insert(ghost);

		auto ghost2 = CEnemys::CreateEnemy(1);
		ghost2->SetPosition(3000.0f, 0.0f);
		PresentObjects.insert(ghost2);
	
		auto Wakanda = CEnemys::CreateEnemy(2);
		Wakanda->SetPosition(1600.0f,0.0f);
		PresentObjects.insert(Wakanda);*/
		/*CBat * bat = new CBat();
		bat->SetPosition(2700.0f, 40.0f);
		PresentObjects.insert(bat);*/

		CAquaman * aqua = new CAquaman();
		aqua->SetPosition(2700.0f, 250.0f);
		PresentObjects.insert(aqua);
		
		CCheckPoint * checkpoint2 = new CCheckPoint();
		checkpoint2->SetPosition(3050.0f, 50.0f);
		checkpoint2->id = 2;
		PresentObjects.insert(checkpoint2);

	}
	default:
		break;
	}

	PresentObjects.insert(p);
	loadDone = true;

};
void Stage1::UpdateObject(float dt)
{
	if (p->IsHitting)
	{
		whip = whip->GetInstance();
		whip->Init(p->whipType);
		grid->AddObject(whip);
		//PresentObjects.insert(whip);
		p->IsHitting = false;

	}
	else if (p->IsThrowing)
	{
		auto w = CWeapons::CreateWeapon(p->weaponTypeCarry);
		w->SetPosition(player->x, player->y);
		PresentObjects.insert(w);
		p->IsThrowing = false;
	}
	auto it = PresentObjects.begin();
	while (it != PresentObjects.end())
	{
		auto obj = *it;
		switch (obj->tag)
		{
		case ENEMY:
			if (obj->isDead)
			{
				auto enemy = (CGhost*)obj;
				it = PresentObjects.erase(it);

				Effect *efc = new Effect();						// effect of enemy dead
				efc->SetPosition(enemy->x, enemy->y);
				PresentObjects.insert(efc);

			}
			else
			{
				
				it++;
			}
			break;
		case HOLDER:
			if (obj->isDead)
			{
				auto holder = (CHolder*)obj;
				grid->RemoveObject(*obj);
				it = PresentObjects.erase(it);
			
				auto itemdrop = CItems::CreateIteam(holder->stored);
				itemdrop->SetPosition(holder->x, holder->y);
				//PresentObjects.insert(itemdrop);
				grid->AddObject(itemdrop);
				it++;
			}
			else it++;
			break;
		case ITEM:
			if (obj->isDead)
			{
				grid->RemoveObject(*obj);
				it = PresentObjects.erase(it);
			}
			else
			{
				it++;
			}
			break;
		case BOX:
		{
			if (obj->type == CHECKPOINT && obj->isDead)
			{
				auto door = (CCheckPoint*)obj;
				if (ChangeMapProc == 2)
				{
					door->IsChangingMap = true;
					door->CurAnimation = door->animations[DOOR_OPEN];
					if (door->CurAnimation->isLastFrame)
					{
						ChangeMapProc = 3;
						door->CurAnimation = door->animations[DOOR_OPENING];
						if (!p->IsWalkingComplete)
							p->ChangeAnimation(new PlayerWalkingState(3100));
					}
				}
				else if (p->IsWalkingComplete)
				{
					door->CurAnimation = door->animations[DOOR_CLOSE];
					if (door->CurAnimation->isLastFrame)
					{
						door->IsChangingMap = false;
						ChangeMapProc = 4;
					}
				}
				level++;
				loadDone = false;
			}
			it++;
			break;
		}
		default:
			it++;

		}
	}
}
void Stage1::ChangeMap(float dt)
{
	camera->IsChangeMap = true;

	if (camera->x + SCREEN_WIDTH / 2 < p->x)
	{
		camera->SetCamPos(camera->x + 0.1 * dt, camera->y);
		ChangeMapProc = 1;
	}
	else
	{
		if (ChangeMapProc == 1) ChangeMapProc = 2;
		if (ChangeMapProc == 4)
		{
			if (camera->x < (3084))
				camera->SetCamPos(camera->x + 0.1 * dt, camera->y);
			else
				ChangeMapProc = 5;
		}
	}
	if (ChangeMapProc == 5)
	{
		p->IsTouchDoor = false;
		camera->IsChangeMap = false;
		camera->map = 3;
	}
}
void Stage1::UpdatePlayer(float dt)
{
	auto it = PresentObjects.begin();
	while (it != PresentObjects.end())
	{
		auto obj = *it;
		if (obj->tag == WEAPON && obj->isDead)
		{
			it = PresentObjects.erase(it);
			grid->RemoveObject(*obj);
			//it++;
		}
		else it++;
	};
	this->UpdateObject(dt);
}
void Stage1::Update(float dt)
{
	PresentObjects.clear();
	PresentObjects = grid->GetObj();
	PresentObjects.insert(p);
	if (level == 2 && !loadDone)
		LoadResources(level);

	Stage1::UpdatePlayer(dt);
	vector<LPGAMEOBJECT> coObjects;
	for (auto o : PresentObjects)
	{
		coObjects.push_back(o);
	}
	for (auto o : PresentObjects)
	{
		if (o->tag != ITEM)
			(o)->Update(dt, &coObjects);
	}
	for (auto o : PresentObjects)
	{
		if (o->tag == ENEMY)
		{
			auto enemy = (CGhost*)o;
			enemy->CollisonGroundWall(dt, &CannotTouchObjects);
		}
		else if (o->tag == PLAYER)
			p->CollisonGroundWall(dt, &CannotTouchObjects);
		else if (o->tag == ITEM)
		{
			o->Update(dt, &CannotTouchObjects);
		}

	}
	if (p->IsTouchDoor)
		ChangeMap(dt);
	else 
	{
		float cx, cy;
		p->GetPosition(cx, cy);
		cx -= SCREEN_WIDTH / 2;
		cy -= SCREEN_HEIGHT / 2;
		camera->SetCamPos(cx, 0);
	}
	map->Update(dt);
	camera->Update();
	grid->Update();
	
};

void Stage1::Render()
{
	map->Render(level);
	for (auto it : PresentObjects)
		(it)->Render();
};
void Stage1::OnKeyDown(int Key)
{
	keyCode[Key] = true;
	if (!camera->IsChangeMap)
		p->OnKeyDown(Key);

};
void Stage1::OnKeyUp(int Key)
{
	keyCode[Key] = false;
	p->OnKeyUp(Key);

	DebugOut(L"[INFO] KeyUp: %d\n", Key);

};