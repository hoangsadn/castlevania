#include "Stage1.h"

Stage1::Stage1()
{
	p = player;
	p->SetPosition(50.0f, 0);
	p->nx = 1;
	p->ChangeAnimation(new PlayerStandingState());
}
void Stage1::LoadResources() 
{
	CTextures * textures = CTextures::GetInstance();


	textures->Add(ID_TEX_MARIO, L"textures\\simon.png", D3DCOLOR_XRGB(255, 0, 255));

	textures->Add(ID_TEX_BBOX, L"textures\\bbox.png", D3DCOLOR_XRGB(255, 0, 255));


	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();


	LPANIMATION ani;


	
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

	ani = new CAnimation(100);		//stand hit left
	ani->Add(10011);
	ani->Add(10016);
	ani->Add(10017);
	ani->Add(10018);
	animations->Add(512, ani);

	ani = new CAnimation(100);	//stand hit right
	ani->Add(10001);
	ani->Add(10019);
	ani->Add(10020);
	ani->Add(10021);
	animations->Add(513, ani);


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
	

	objects.push_back(p);
};
void Stage1::Update(float dt) 
{
	vector<LPGAMEOBJECT> coObjects;
	for (int i = 1; i < objects.size(); i++)
	{
		coObjects.push_back(objects[i]);
	}

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt, &coObjects);
	}
	float cx, cy;
	p->GetPosition(cx, cy);
	//camera->SetPosition(cx, 0.0f);
};

void Stage1::Render() 
{
	for (int i = 0; i < objects.size(); i++)
		objects[i]->Render();
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