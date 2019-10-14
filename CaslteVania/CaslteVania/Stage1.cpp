#include "Stage1.h"

Stage1::Stage1()
{
	p = player;
	whip = whip->GetInstance();
	p->SetPosition(50.0f, 0);
	p->nx = 1;
	p->ChangeAnimation(new PlayerStandingState());
}
void Stage1::LoadResources() 
{
	CTextures * textures = CTextures::GetInstance();


	textures->Add(ID_TEX_MARIO, L"textures\\simon.png", D3DCOLOR_XRGB(255, 0, 255));

	textures->Add(ID_TEX_BBOX, L"textures\\bbox.png", D3DCOLOR_XRGB(255, 0, 255));
	 
	textures->Add(ID_TEX_WHIP, L"textures\\morningstar.png", D3DCOLOR_XRGB(255, 0, 255));


	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();


	LPANIMATION ani;

	LPDIRECT3DTEXTURE9 textWhip = textures->Get(ID_TEX_WHIP);
	sprites->Add(20001, 0, 0, 158, 68, textWhip);		//whip one right
	sprites->Add(20002, 158, 0, 317, 68, textWhip);
	sprites->Add(20003, 317, 0, 474, 68, textWhip);
	sprites->Add(20004, 474, 0, 635, 68, textWhip);

	sprites->Add(20011, 0, 68, 158, 136, textWhip);		//whip two right
	sprites->Add(20012, 158, 68, 317, 136, textWhip);
	sprites->Add(20013, 317, 68, 474, 136, textWhip);
	sprites->Add(20014, 474, 68, 635, 136, textWhip);

	sprites->Add(20021, 0, 136, 158, 204, textWhip);	//whip three right
	sprites->Add(20022, 158, 136, 317, 204, textWhip);
	sprites->Add(20023, 317, 136, 474, 204, textWhip);
	sprites->Add(20024, 474, 136, 635, 204, textWhip);

	sprites->Add(20034, 0, 204, 158, 272, textWhip);	//whip one left
	sprites->Add(20033, 158, 204, 317, 272, textWhip);
	sprites->Add(20032, 317, 204, 474, 272, textWhip);
	sprites->Add(20031, 474, 204, 635, 272, textWhip);

	sprites->Add(20044, 0, 272, 158, 340, textWhip);	//whip two left
	sprites->Add(20043, 158, 272, 317, 340, textWhip);
	sprites->Add(20042, 317, 272, 474, 340, textWhip);
	sprites->Add(20041, 474, 272, 635, 340, textWhip);

	sprites->Add(20054, 0, 340, 158, 408, textWhip);	//whip two left
	sprites->Add(20053, 158, 340, 317, 408, textWhip);
	sprites->Add(20052, 317, 340, 474, 408, textWhip);
	sprites->Add(20051, 474, 340, 635, 408, textWhip);


	
	LPDIRECT3DTEXTURE9 texMario = textures->Get(ID_TEX_MARIO);

	sprites->Add(10001, 435, 200, 468, 261, texMario);		// idle right

	sprites->Add(10002, 375, 200, 408, 261, texMario);		// walk
	sprites->Add(10003, 312, 200, 345, 261, texMario);
	sprites->Add(10004, 255, 200, 288, 261, texMario);
	sprites->Add(10005, 195, 199, 228, 260, texMario);		//jump +down right
	sprites->Add(10006, 195, 199, 228, 243, texMario);		//down right


	sprites->Add(10011, 11, 2, 44, 63, texMario);		// idle left

	sprites->Add(10012, 73, 2, 106, 63, texMario);		// walk
	sprites->Add(10013, 134, 2, 167, 63, texMario);
	sprites->Add(10014, 191, 2, 224, 63, texMario);
	sprites->Add(10015, 252, 1, 285, 64, texMario);		//jump+ down left
	sprites->Add(10010, 252, 1, 285, 47, texMario);		//down left

	sprites->Add(10016, 300, 4, 360, 64, texMario);		//hit stand left
	sprites->Add(10017, 360, 4, 420, 64, texMario);
	sprites->Add(10018, 420, 4, 480, 64, texMario);

	sprites->Add(10019, 120, 204, 180, 264, texMario);	//hit stand right
	sprites->Add(10020, 60, 204, 120, 264, texMario);
	sprites->Add(10021, 0, 204, 60, 264, texMario);
	

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

	ani = new CAnimation(300);
	ani->Add(10005);	//jump right
	animations->Add(509, ani);

	ani = new CAnimation(300);
	ani->Add(10015);	//jump left
	animations->Add(508, ani);

	ani = new CAnimation(200);
	ani->Add(10006);	//down right
	animations->Add(510, ani);

	ani = new CAnimation(300);
	ani->Add(10010);	//down left
	animations->Add(511, ani);

	ani = new CAnimation(1000);		//stand hit left
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


	ani = new CAnimation(1000); //Whip one right
	ani->Add(20004);
	ani->Add(20001);
	ani->Add(20002);
	ani->Add(20003);
	animations->Add(600, ani);

	ani = new CAnimation(100); //Whip two right
	ani->Add(20011);
	ani->Add(20012);
	ani->Add(20013);
	ani->Add(20014);
	animations->Add(601, ani);

	ani = new CAnimation(100); //Whip three right
	ani->Add(20021);
	ani->Add(20022);
	ani->Add(20023);
	ani->Add(20024);
	animations->Add(602, ani);

	ani = new CAnimation(100); //Whip one right
	ani->Add(20031);
	ani->Add(20032);
	ani->Add(20033);
	ani->Add(20034);
	animations->Add(603, ani);

	ani = new CAnimation(1000); //Whip one left
	ani->Add(20041);
	ani->Add(20042);
	ani->Add(20043);
	ani->Add(20044);
	animations->Add(604, ani);

	ani = new CAnimation(100); //Whip two left
	ani->Add(20051);
	ani->Add(20052);
	ani->Add(20053);
	ani->Add(20054);
	animations->Add(605, ani);

	ani = new CAnimation(100); //Whip three left
	ani->Add(20061);
	ani->Add(20062);
	ani->Add(20063);
	ani->Add(20064);
	animations->Add(606, ani);


	whip->AddAnimation(600, WHIP_ONE_RIGHT);
	whip->AddAnimation(604, WHIP_ONE_LEFT);




	p->AddAnimation(400, STANDING_RIGHT);		// idle right big
	p->AddAnimation(401, STANDING_LEFT);		// idle left big


	p->AddAnimation(500, WALKING_RIGHT);		// walk right big
	p->AddAnimation(501, WALKING_LEFT);		// walk left big

	p->AddAnimation(508, JUMPING_LEFT);		//jump left
	p->AddAnimation(509, JUMPING_RIGHT);	//jump right
	
	p->AddAnimation(510, DOWNING_RIGHT);	 //down right
	p->AddAnimation(511, DOWNING_LEFT);		//down left

	p->AddAnimation(512, HITTING_STAND_LEFT);
	p->AddAnimation(513, HITTING_STAND_RIGHT);

	camera->SetPosition(100.f, 200);

	p->Revival();

	objects.insert(p);
	objects.insert(whip);

};
void Stage1::UpdatePlayer()
{
	auto it = PresentObjects.begin();
	while ( it != PresentObjects.end())
	{
		if (dynamic_cast<CWhip*> (*it)&& !p->IsHitting)
		{
			it = PresentObjects.erase(it);
		}
		else it++;
	};
}
void Stage1::Update(float dt) 
{
	vector<LPGAMEOBJECT> coObjects;
	unordered_set<CGameObject*> ::iterator itr;
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
	float cx, cy;
	p->GetPosition(cx, cy);
	//camera->SetPosition(cx, 0.0f);
};

void Stage1::Render() 
{
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