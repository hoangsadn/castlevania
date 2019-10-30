#include "Stage1.h"
#include "Whip.h"
#include "Brick.h"
#include "Simon.h"
#include "HolderFirePillar.h"
#include "HolderCandle.h"
#include "Item.h"
#include "Effect.h"
#include "Items.h"
#include "Weapons.h"
#include "Door.h"

class CBrick;
vector<LPGAMEOBJECT> CannotTouchObjects;


Stage1::Stage1()
{
	camera = camera->GetInstance();
	camera->SetRect(SCREEN_WIDTH, SCREEN_HEIGHT);
	map = map->GetInstance();

}
void Stage1::LoadObjects()
{
	ifstream File;
	File.open(L"text\\obj\\Scene2_Object.txt");
	float posX, posY, width, height;
	string str;

	while (!File.eof())
	{

		File >> str;

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
void Stage1::LoadResources() 
{
	auto a = new CGlobalConfig();
	a->TypeMapToString();


	
	CTextures * textures = CTextures::GetInstance();
	textures->LoadResources();
	CSprites * sprites = CSprites::GetInstance();
	sprites->LoadResources();
	CAnimations * animations = CAnimations::GetInstance();	
	animations->LoadResources();
	
	LoadObjects();
	
	

	

	CDoor * door = new CDoor();
	door->SetPosition(1200.0f, 235.0f);
	PresentObjects.insert(door);


	p = player;
	p->Revival();

	PresentObjects.insert(p);


};
void Stage1::UpdateObject(float dt)
{
	if (p->IsHitting)
	{
		whip = whip->GetInstance();
		whip->Init(p->whipType);
		PresentObjects.insert(whip);
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

		case HOLDER:
			if (obj->isDead)
			{
				auto holder = (CHolder*)obj;
				it = PresentObjects.erase(it);

				Effect *efc = new Effect();						// effect of holder dead
				efc->SetPosition(holder->x, holder->y);
				PresentObjects.insert(efc);

				auto itemdrop = CItems::CreateIteam(holder->stored);
				itemdrop->SetPosition(holder->x, holder->y);
				PresentObjects.insert(itemdrop);

			}
			else it++;
			break;
		case ITEM:
			if (obj->isDead)
				it = PresentObjects.erase(it);
			else
			{
				obj->Update(dt, &CannotTouchObjects);
				it++;
			}
			break;
		case EFFECT:
		{
			auto effect = (Effect*)obj;
			if (effect->CurAnimation->isLastFrame)
				it = PresentObjects.erase(it);
			else it++;
			break;
		}
		default:
			it++;
		
		}
	}
}
void Stage1::UpdatePlayer(float dt)
{
	auto it = PresentObjects.begin();
	while ( it != PresentObjects.end())
	{
		auto obj = *it;
		if (obj->tag == WEAPON && obj->isDead)
		{
			it = PresentObjects.erase(it);
		}
		
		else it++;
	};
	this->UpdateObject(dt);
	p->CollisonGroundWall(dt, &CannotTouchObjects);
}
void Stage1::Update(float dt) 
{
	Stage1::UpdatePlayer(dt);
	vector<LPGAMEOBJECT> coObjects;
	for (auto o : PresentObjects)
	{
		coObjects.push_back(o);
	}
	

	for (auto o: PresentObjects)
	{
		(o)->Update(dt, &coObjects);
	}

	map->Update(dt);
	float cx, cy;
	p->GetPosition(cx, cy);

	cx -= SCREEN_WIDTH / 2;
	cy -= SCREEN_HEIGHT / 2;
	camera->SetCamPos(cx, 0);
	camera->Update();
};

void Stage1::Render() 
{
	map->Render();
	for (auto it : PresentObjects)
		(it)->Render();
};
void Stage1::OnKeyDown(int Key)
{	
	keyCode[Key] = true;
	p->OnKeyDown(Key);

};
void Stage1::OnKeyUp(int Key) 
{	
	keyCode[Key] = false;
	p->OnKeyUp(Key);

	DebugOut(L"[INFO] KeyUp: %d\n", Key);

};