#include "IntroScene.h"
#include "Simon.h"
#include "PlayerWalkingState.h"
#include "PlayerStandIntroState.h"
IntroScene::IntroScene()
{

	auto a = new CGlobalConfig();
	a->TypeMapToString();
	CTextures * textures = CTextures::GetInstance();
	textures->LoadResources();
	CSprites * sprites = CSprites::GetInstance();
	sprites->LoadResources();
	CAnimations * animations = CAnimations::GetInstance();
	animations->LoadResources();
	p = player;
	ProcessScene = 1;
	AddAnimation(1000, TITLE_SCREEN);
	AddAnimation(1001, BAT_CASTLE_FLY);
	AddAnimation(1002, BAT_CASTLE_FLY_NOT_MOVE);
	AddAnimation(1003, CASTLE_SCREEN);
	AddAnimation(1004, HELICOPTER);
	AddAnimation(1005, BAT_INTRO_SMALL_FLY);
	BatFly = this->animations[BAT_CASTLE_FLY];
	TitleScreen = this->animations[TITLE_SCREEN];
	helicopter = this->animations[HELICOPTER];
	CastleScreen = this->animations[CASTLE_SCREEN];
	bat = this->animations[BAT_INTRO_SMALL_FLY];
	
}
void IntroScene::AddAnimation(int aniId, TYPE type)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	animations[type] = ani;
}
void IntroScene::Render()
{
	if (ProcessScene == 1)
	{
		TitleScreen->Render(0, 0);
		BatFly->Render(260, 200);
	}
	else if (ProcessScene == 2)
	{
		CastleScreen->Render(0, 0);
		helicopter->Render(400, 150);
		bat->Render(250, 179);
		p->Render();
	}

}
void IntroScene::Update(float dt)
{
	if (BatFly->isLastFrame && ProcessScene ==1)
		BatFly = this->animations[BAT_CASTLE_FLY_NOT_MOVE];
	if (ProcessScene == 2)
	{
		p->Update(dt);
		p->x += p->dx;
		if (p->IsWalkingComplete)
		{
			p->ChangeAnimation(new PlayerStandIntroState());
			if (GetTickCount() - time > 5000)
			{
				ManagerScene::GetInstance()->PlayScene(new PlayStage());
				ManagerScene::GetInstance()->PresentScene->LoadResources(1);
			}
		}
	}
}
void IntroScene::OnKeyDown(int keyCode)
{
	if (keyCode == DIK_RETURN && ProcessScene == 1 )
	{
		ProcessScene = 2;
		p->Revival();
		p->SetPosition(500, 335);
		p->ChangeAnimation(new PlayerWalkingState(255));
		time = GetTickCount();
		p->IsOnIntro = true;
	}
}
IntroScene::~IntroScene()
{
}
