#include "Boss.h"
#include "Simon.h"
#include <math.h>

void Boss::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = left + width;
	bottom = top + height;
}
float i = 0;
float j = 0;
int Boss::Slerp(int n1, int n2, float perc)
{
	int diff = n2 - n1;

	return n1 + (diff * perc);
}
float Boss::Lerp(float a, float b, float f)
{
	return a + f * (b - a);
}
void Boss::MoveStraight(float x1, float y1, float x2, float y2)
{
	if (i < 0) i = 0;
	x = Lerp(x1, x2, i);
	y = Lerp(y1, y2, i);


	if (i < 1)
		i += 0.01;

}
void Boss::MoveCurved(float x1, float y1, float x2, float y2, float x3, float y3)
{
	if (j < 0) j = 0;
	float xa = Slerp(x1, x2, j);
	float ya = Slerp(y1, y2, j);
	float xb = Slerp(x2, x3, j);
	float yb = Slerp(y2, y3, j);



	if (j < 1)
		j += 0.01;

	x = Slerp(xa, xb, j);
	y = Slerp(ya, yb, j);

}
void Boss::RepareToMove()
{
	if (player->y+ player->height < 273 )
		BossPos = PosBossAttack[rand() % 3];
	else 
		BossPos = PosBossAttack[3 + rand() % 3];
	
	GAMELOG("pos %f", player->y + player->height);
	state = BOSS_MOVE;
	BossPrePos.x = x;
	BossPrePos.y = y;
	isGetPosAttack = false;
	isAttackSimon = false;
	i = 0.01;
	j = 0.01;
}
void Boss::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	//GAMELOG("health %d", health);

	if (abs(abs(player->x) - abs(x)) < 100 && !isActive)
	{
		isActive = true;
		CurAnimation = animations[BOSS_MOVE];
		RepareToMove();
	}
	if (isActive)
	{
		if (state == BOSS_MOVE && !isGetPosAttack)
		{
			//di toi cho tan cong 
			if (i < 1)
			{
				MoveStraight(BossPrePos.x, BossPrePos.y, BossPos.x, BossPos.y);

				waitTime = GetTickCount();
				if (player->x > x)
				{
					int r =  END_MAP5 - player->x - BOSS_WIDTH;
					r = r <= 0 ? 1 : r;
					CPos.x = player->x + rand() % r;
					CPos.y = (player->y + player->height) - rand() % 60;

				}
				else
				{
					int r = player->x - CAMERA->x;
					r = r < 0 ? 1 : r;
					CPos.x = player->x - rand() % r;
					CPos.y = (player->y + player->height) - rand() % 60;
				}
			}
			else if (GetTickCount() - waitTime > 2000)
			{
				isGetPosAttack = true;
				state = BOSS_READY_ATTACK;
				SimonPos.x = player->x;
				SimonPos.y = player->y + player->height;

			}
		}
		else if (state == BOSS_READY_ATTACK && !isAttackSimon)
		{
			{
				if (j < 1)
				{
					MoveCurved(BossPos.x, BossPos.y, SimonPos.x, SimonPos.y, CPos.x, CPos.y);

				}
				else
				{
					RepareToMove();
				}


			}
		}
	}
	UpdatePosition(dt);

	if (isBuring)
	{

		LPANIMATION ani = new CAnimation(50);
		ani->Add(50001);
		ani->Add(50002);
		ani->Add(50003);
		EffectHit = ani;
		isBuring = false;
		ishitting = true;
		i -= 0.01;
		j -= 0.01;
	}
	if (ishitting && EffectHit->isLastFrame)
	{
		player->bossHealth--;
		EffectHit->isLastFrame = false;
		EffectHit->currentFrame = -1;
		EffectHit = NULL;
		ishitting = false;

	}

	if (player->bossHealth == 0)
	{
		isDead = true;

	}
}

void Boss::UpdatePosition(float dt)
{

}
void Boss::Render()
{
	CurAnimation->Render(x, y, 255);
	if (EffectHit != NULL)
		EffectHit->Render(x, y, 255);
	RenderBoundingBox();
}
Boss::~Boss()
{
}
