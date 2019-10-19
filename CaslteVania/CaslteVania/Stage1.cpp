#include "Stage1.h"

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
	CAnimations * animations = CAnimations::GetInstance();

	sprites->LoadResources();
	LPANIMATION ani;
	
	animations->LoadResources();

	ani = new CAnimation(100);	// idle big right
	ani->Add(10001);
	animations->Add(400, ani);

	ani = new CAnimation(100);	// idle big left
	ani->Add(10011);
	animations->Add(401, ani);

	ani = new CAnimation(100);	// walk right big
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	ani->Add(10004);
	animations->Add(500, ani);

	ani = new CAnimation(100);	// // walk left big
	ani->Add(10011);
	ani->Add(10012);
	ani->Add(10013);
	ani->Add(10014);
	animations->Add(501, ani);

	ani = new CAnimation(100);
	ani->Add(10005);	//jump right
	animations->Add(509, ani);

	ani = new CAnimation(100);
	ani->Add(10015);	//jump left
	animations->Add(508, ani);

	ani = new CAnimation(100);
	ani->Add(10006);	//down right
	animations->Add(510, ani);

	ani = new CAnimation(100);
	ani->Add(10010);	//down left
	animations->Add(511, ani);

	ani = new CAnimation(100);		//stand hit left
	ani->Add(10011);
	ani->Add(10016);
	ani->Add(10017);
	ani->Add(10018);
	animations->Add(512, ani);

	ani = new CAnimation(1000);	//stand hit right
	ani->Add(10001);
	ani->Add(10019);
	ani->Add(10020);
	ani->Add(10021);
	animations->Add(513, ani);

	ani = new CAnimation(1000);	//down hit right
	ani->Add(10006);
	ani->Add(10026);
	ani->Add(10027);
	ani->Add(10028);
	animations->Add(514, ani);

	ani = new CAnimation(100);	//down hit left
	ani->Add(10010);
	ani->Add(10022);
	ani->Add(10023);
	ani->Add(10024);
	animations->Add(515, ani);



	ani = new CAnimation(100); //Whip one left
	ani->Add(20001);
	ani->Add(20002);
	ani->Add(20003);
	ani->Add(20004);
	animations->Add(600, ani);

	ani = new CAnimation(100); //Whip two left
	ani->Add(20011);
	ani->Add(20012);
	ani->Add(20013);
	ani->Add(20014);
	animations->Add(601, ani);

	ani = new CAnimation(100); //Whip three left
	ani->Add(20021);
	ani->Add(20022);
	ani->Add(20023);
	ani->Add(20024);
	animations->Add(602, ani);

	ani = new CAnimation(1000); //Whip one right
	ani->Add(20031);
	ani->Add(20032);
	ani->Add(20033);
	ani->Add(20034);
	animations->Add(603, ani);

	ani = new CAnimation(100); //Whip two right
	ani->Add(20041);
	ani->Add(20042);
	ani->Add(20043);
	ani->Add(20044);
	animations->Add(604, ani);

	ani = new CAnimation(100); //Whip three right
	ani->Add(20051);
	ani->Add(20052);
	ani->Add(20053);
	ani->Add(20054);
	animations->Add(605, ani);


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
}
void Stage1::UpdatePlayer()
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
}
void Stage1::Update(float dt) 
{
	
	vector<LPGAMEOBJECT> coObjects;
	for (auto o : objects) 
	{
		coObjects.push_back(o);
		PresentObjects.insert(o);	
	}
	Stage1::UpdatePlayer();

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