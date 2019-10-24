#include "Stage1.h"
#include "Whip.h"
#include "Brick.h"
#include "Simon.h"
#include "HolderFirePillar.h"
#include "Item.h"
#include "Effect.h"
#include "Items.h"
class CBrick;
vector<LPGAMEOBJECT> CannotTouchObjects;
Stage1::Stage1()
{
	camera = camera->GetInstance();
	camera->SetRect(SCREEN_WIDTH, SCREEN_HEIGHT);
	map = map->GetInstance();

}
void Stage1::LoadResources() 
{
	CTextures * textures = CTextures::GetInstance();
	textures->LoadResources();
	CSprites * sprites = CSprites::GetInstance();
	sprites->LoadResources();
	CAnimations * animations = CAnimations::GetInstance();	
	animations->LoadResources();

	brick = brick->GetInstance();
	brick->SetPosition(0.0f, 300.0f);
	CannotTouchObjects.push_back(brick);

	CHolderFirePillar * cotlua = new CHolderFirePillar(MORNING_STAR);
	cotlua->SetPosition(300.0f, 235.0f);
	PresentObjects.insert(cotlua);
	
	CHolderFirePillar * cotlua2 = new CHolderFirePillar(BIG_HEART);
	cotlua2->SetPosition(600.0f, 235.0f);
	PresentObjects.insert(cotlua2);

	p = player;
	p->Revival();

	PresentObjects.insert(p);


};
void Stage1::UpdateObject(float dt)
{
	if (!p->UsingWhip&& p->IsHitting)
	{
		whip = whip->GetInstance();
		whip->Init(p->whipType);
		PresentObjects.insert(whip);
		p->UsingWhip = true;
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
		if (dynamic_cast<CWhip*> (*it) && !p->IsHitting)
		{
			it = PresentObjects.erase(it);
			p->UsingWhip = false;
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