#pragma once

#include "Animations.h"

using namespace std;

#define ID_TEX_BBOX -100		// special texture to draw object bounding box

class CGameObject;
typedef CGameObject * LPGAMEOBJECT;
class CAnimation;
struct CCollisionEvent;
typedef CCollisionEvent * LPCOLLISIONEVENT;

struct CCollisionEvent
{
	LPGAMEOBJECT obj;
	float t, nx, ny;
	CCollisionEvent(float t, float nx, float ny, LPGAMEOBJECT obj = NULL) { this->t = t; this->nx = nx; this->ny = ny; this->obj = obj; }

	static bool compare(const LPCOLLISIONEVENT &a, LPCOLLISIONEVENT &b)
	{
		return a->t < b->t;
	}
};



class CGameObject
{
public:

	float x;
	float y;

	float dx;	// dx = vx*dt
	float dy;	// dy = vy*dt

	float width, height;
	float vx;
	float vy;

	int nx;
	int ny;

	TYPE type;
	TAG tag;
	DWORD dt;
	bool isDead;
	std::unordered_map<int, CAnimation*> animations;

public:
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetWidthHeight(float w, float h) { this->width = w, this->height = h; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }
	void GetPosition(float &x, float &y) { x = this->x; y = this->y; }
	void GetSpeed(float &vx, float &vy) { vx = this->vx; vy = this->vy; }


	void RenderBoundingBox();

	LPCOLLISIONEVENT SweptAABBEx(LPGAMEOBJECT coO);
	void CalcPotentialCollisions(vector<LPGAMEOBJECT> *coObjects, vector<LPCOLLISIONEVENT> &coEvents);
	void FilterCollision(
		vector<LPCOLLISIONEVENT> &coEvents,
		vector<LPCOLLISIONEVENT> &coEventsResult,
		float &min_tx,
		float &min_ty,
		float &nx,
		float &ny);
	bool IsCollision(float left1, float top1, float right1, float bottom1, 
					float left2, float top2, float right2, float bottom2);
	void AddAnimation(int aniId, STATENAME NameState);
	void AddAnimation(int aniId, TYPE type);

	CGameObject();

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom) = 0;
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render() = 0;
	bool IsCollisionAABB(RECT rect1, RECT rect2);
	RECT GetRect();

	~CGameObject();
};


