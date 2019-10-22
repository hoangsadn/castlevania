#include "Stage1.h"
#include "Whip.h"
#include "Brick.h"
#include "Simon.h"
#include "StoredItemFirePillar.h"
class CBrick;
vector<LPGAMEOBJECT> CannotTouchObjects;
Stage1::Stage1()
{
	camera = camera->GetInstance();
	camera->SetRect(SCREEN_WIDTH, SCREEN_HEIGHT);
	map = map->GetInstance();
	whip = whip->GetInstance();

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

	CStoredItemFirePillar * cotlua = new CStoredItemFirePillar();
	cotlua->SetPosition(300.0f, 250.0f);
	cotlua->isDead = false;
	objects.insert(cotlua);
	

	p = player;
	p->Revival();

	objects.insert(p);


};
void Stage1::UpdateObject()
{
	if (!p->UsingWhip&& p->IsHitting)
	{
		whip = new CWhip();
		whip->Init();
		PresentObjects.insert(whip);
		p->UsingWhip = true;
	}
	auto it = PresentObjects.begin();
	while (it != PresentObjects.end())
	{
		if (dynamic_cast<CStoredItemFirePillar*> (*it))
		{
			CStoredItemFirePillar *FirePillar = dynamic_cast<CStoredItemFirePillar *>(*it);
			if (FirePillar->isDead)
				it = PresentObjects.erase(it);
			else it++;
		}
		else it++;
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
	this->UpdateObject();
	p->CollisonGroundWall(dt, &CannotTouchObjects);
}
void Stage1::Update(float dt) 
{
	
	vector<LPGAMEOBJECT> coObjects;
	for (auto o : objects) 
	{
		coObjects.push_back(o);
		PresentObjects.insert(o);	
	}
	Stage1::UpdatePlayer(dt);

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