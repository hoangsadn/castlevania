#include "Stage1.h"



void Stage1::LoadResources() 
{
	CTextures * textures = CTextures::GetInstance();


	textures->Add(ID_TEX_MARIO, L"textures\\simon.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_MISC, L"textures\\misc.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_ENEMY, L"textures\\enemies.png", D3DCOLOR_XRGB(3, 26, 110));


	textures->Add(ID_TEX_BBOX, L"textures\\bbox.png", D3DCOLOR_XRGB(255, 0, 255));


	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();




	LPDIRECT3DTEXTURE9 texMisc = textures->Get(ID_TEX_MISC);
	sprites->Add(20001, 408, 225, 424, 241, texMisc);

	LPDIRECT3DTEXTURE9 texEnemy = textures->Get(ID_TEX_ENEMY);
	sprites->Add(30001, 5, 14, 21, 29, texEnemy);
	sprites->Add(30002, 25, 14, 41, 29, texEnemy);

	sprites->Add(30003, 45, 21, 61, 29, texEnemy); // die sprite

	LPANIMATION ani;




	ani = new CAnimation(100);		// Mario die
	ani->Add(10099);
	animations->Add(599, ani);



	ani = new CAnimation(100);		// brick
	ani->Add(20001);
	animations->Add(601, ani);

	ani = new CAnimation(300);		// Goomba walk
	ani->Add(30001);
	ani->Add(30002);
	animations->Add(701, ani);

	ani = new CAnimation(1000);		// Goomba dead
	ani->Add(30003);
	animations->Add(702, ani);




	for (int i = 0; i < 1; i++)
	{
		CBrick *brick = new CBrick();
		brick->AddAnimation(601);
		brick->SetPosition(100.0f + i * 60.0f, 44.0f);
		objects.push_back(brick);

		brick = new CBrick();
		brick->AddAnimation(601);
		brick->SetPosition(100.0f + i * 60.0f, 80.0f);
		objects.push_back(brick);

		brick = new CBrick();
		brick->AddAnimation(601);
		brick->SetPosition(84.0f + i * 60.0f, 90.0f);
		objects.push_back(brick);
	}


	for (int i = 0; i < 30; i++)
	{
		CBrick *brick = new CBrick();
		brick->AddAnimation(601);
		brick->SetPosition(0 + i * 16.0f, 150);
		objects.push_back(brick);
	}

	// and Goombas 
	for (int i = 0; i < 4; i++)
	{
		goomba = new CGoomba();
		goomba->AddAnimation(701);
		goomba->AddAnimation(702);
		goomba->SetPosition(200 + i * 60, 135);
		goomba->SetState(GOOMBA_STATE_WALKING);
		objects.push_back(goomba);
	}
	
	LPDIRECT3DTEXTURE9 texMario = textures->Get(ID_TEX_MARIO);

	// big
	sprites->Add(10001, 435, 200, 468, 261, texMario);		// idle right

	sprites->Add(10002, 375, 200, 408, 261, texMario);		// walk
	sprites->Add(10003, 312, 200, 345, 261, texMario);
	sprites->Add(10004, 255, 200, 288, 261, texMario);
	sprites->Add(10005, 195, 199, 228, 260, texMario);		//jump +down right

	sprites->Add(10011, 11, 2, 44, 63, texMario);		// idle left
	sprites->Add(10012, 73, 2, 106, 63, texMario);		// walk
	sprites->Add(10013, 134, 2, 167, 63, texMario);
	sprites->Add(10014, 191, 2, 224, 63, texMario);
	sprites->Add(10015, 252, 1, 285, 64, texMario);		//jump+ down left

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

	ani = new CAnimation(100);
	ani->Add(10005);	//jump right
	animations->Add(509, ani);

	ani = new CAnimation(100);
	ani->Add(10015);	//jump left
	animations->Add(508, ani);

	ani = new CAnimation(200);
	ani->Add(10005);	//jump right
	animations->Add(510, ani);

	ani = new CAnimation(1200);
	ani->Add(10015);	//jump left
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


	sprites->Add(10099, 215, 120, 231, 135, texMario);		// die Mario
	player = new CMario();
	player->AddAnimation(400);		// idle right big
	player->AddAnimation(401);		// idle left big
	player->AddAnimation(402);		// idle right small
	player->AddAnimation(403);		// idle left small

	player->AddAnimation(500);		// walk right big
	player->AddAnimation(501);		// walk left big
	player->AddAnimation(502);		// walk right small
	player->AddAnimation(503);		// walk left big

	player->AddAnimation(508);	//jump left
	player->AddAnimation(509);	//jump right
	player->AddAnimation(510);	//down right
	player->AddAnimation(511);	//down left
	player->AddAnimation(512);	//stand hit left
	player->AddAnimation(513);	//stand hit right 

	player->AddAnimation(599);		// die




	player->SetPosition(50.0f, 0);
	
	objects.push_back(player);
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
};

void Stage1::Render() 
{
	for (int i = 0; i < objects.size(); i++)
		objects[i]->Render();
};
void Stage1::OnKeyDown(int KeyCode) 
{
	
	switch (KeyCode)
	{
	case DIK_SPACE:
		player->SetState(MARIO_STATE_JUMP);
		break;
	case DIK_A: // reset
		player->SetState(MARIO_STATE_IDLE);
		player->SetLevel(MARIO_LEVEL_BIG);
		player->SetPosition(50.0f, 0.0f);
		player->SetSpeed(0, 0);
		break;
	}
};
void Stage1::OnKeyUp(int keyCode) 
{
	DebugOut(L"[INFO] KeyUp: %d\n", keyCode);

};