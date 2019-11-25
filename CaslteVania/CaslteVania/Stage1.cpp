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

		map->LoadResources(level);
		
		
		grid->CreateFileGird(level);
		p = player;
		p->Revival();

		
		break;

	}
	case 2:
	{

		map->LoadResources(level);
		grid->CreateFileGird(level);
	
		p->SetPosition(2900.0f, 0.0f);
		
		CStair * stair = new CStair(STAIR_BOTTOM_RIGHT);
		stair->SetPosition(1220.0f, 315.0f);
		PresentObjects.insert(stair);

		CStair * stair2 = new CStair(STAIR_TOP_LEFT);
		stair2->SetPosition(1347.0f, 72.0f);
		PresentObjects.insert(stair2);


		auto ghost = CEnemys::CreateEnemy(1);
		ghost->SetPosition(1500.0f, 0.0f);
		PresentObjects.insert(ghost);

		auto ghost2 = CEnemys::CreateEnemy(1);
		ghost2->SetPosition(3000.0f, 0.0f);
		PresentObjects.insert(ghost2);
	
		auto Wakanda = CEnemys::CreateEnemy(2);
		Wakanda->SetPosition(1600.0f,0.0f);
		PresentObjects.insert(Wakanda);
		CBat * bat = new CBat();
		bat->SetPosition(2700.0f, 40.0f);
		grid->AddObject(bat);

		CAquaman * aqua = new CAquaman();
		aqua->SetPosition(2700.0f, 250.0f);
		grid->AddObject(aqua);
		
		CCheckPoint * checkpoint2 = new CCheckPoint();

		checkpoint2->SetPosition(3050.0f, 50.0f);
		checkpoint2->id = 2;
		checkpoint2->type = DOOR;
		grid->AddObject(checkpoint2);

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
		p->IsHitting = false;

	}
	else if (p->IsThrowing)
	{
		auto w = CWeapons::CreateWeapon(p->weaponTypeCarry);
		
		grid->AddObject(w);
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
				enemy->CurAnimation = enemy->animations[EFFECT_DEAD];
				
				if (enemy->CurAnimation->isLastFrame)
				{
					//enemy->CurAnimation->isLastFrame = false;
					//enemy->CurAnimation->currentFrame = -1;
					grid->RemoveObject(*enemy);
					it = PresentObjects.erase(it);
				}
				it++;
			}
			else it++;
			break;
		case HOLDER:
			if (obj->isDead)
			{
				auto holder = (CHolder*)obj;
				holder->DeadState();
				
				if (holder->CurAnimation->isLastFrame)
				{
					grid->RemoveObject(*obj);
					it = PresentObjects.erase(it);
					//holder->CurAnimation->isLastFrame = false;
					//holder->CurAnimation->currentFrame = -1;

					auto itemdrop = CItems::CreateIteam(holder->stored);
					itemdrop->SetPosition(holder->x, holder->y);
					grid->AddObject(itemdrop);
				}

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
			else it++;
			break;
		case BOX:
		{
			if (obj->type == DOOR && obj->isDead)
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
				it++;
			}
			else if (obj->type == CHECKPOINT && obj->isDead)
			{
				if (!p->IsWalkingComplete)
				{
					p->ChangeAnimation(new PlayerWalkingState(1500));
					
				}
				else 
				{
					level++;
					loadDone = false;
					p->IsWalkingComplete = false;
				}
				it++;
			}
			else 
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
		p->IsWalkingComplete = false;
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
		}
		else it++;
	};
	this->UpdateObject(dt);
}
void Stage1::Update(float dt)
{
	vector<LPGAMEOBJECT> coObjects;
	
	PresentObjects.clear();
	
	PresentObjects = grid->GetObj();
	PresentObjects.insert(p);
	CannotTouchObjects.clear();
	CannotTouchObjects = grid->GetWall();
	
	CHolderCandle * connerwall = new CHolderCandle(SMALL_HEART);
	connerwall->CurAnimation = connerwall->animations[CONNER_WALL];
	connerwall->SetPosition(1400.0f, 180.0f);
	PresentObjects.insert(connerwall);
	

	if (level == 2 && !loadDone)
		LoadResources(level);

	UpdatePlayer(dt);
	
	for (auto o : PresentObjects)
	{
		coObjects.push_back(o);
	}

	for (auto o : PresentObjects)
	{
		float posPrevUpdateX = o->x;
		float posPrevUpdateY = o->y;
		if (o->tag != ITEM)
		{
			if (o->tag == ENEMY && !p->freeze)
				(o)->Update(dt, &coObjects);
			else if(o->tag != ENEMY)
				(o)->Update(dt, &coObjects);
		}

		if ((o->tag == WEAPON && o->type != WHIP) || o->tag ==ENEMY)
		{
			grid->UpdateObject(*o, posPrevUpdateX, posPrevUpdateY);
		}
	}
	for (auto o : PresentObjects)
	{
		if (o->tag == ENEMY)
		{
			auto enemy = (CGhost*)o;
			if (!p->freeze)
				enemy->CollisonGroundWall(dt, &CannotTouchObjects);
		}
		else if (o->tag == PLAYER)
			p->CollisonGroundWall(dt, &CannotTouchObjects);
		else if (o->type == HOLLY_WATER && o->tag == WEAPON)
		{
			auto w = (CHollyWater*)o;
			w->CollisonGroundWall(dt, &CannotTouchObjects);
		}
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