#pragma once

#include "Math.h"
#include <chrono> 

using namespace maths;
class Sprite;
class Texture;

struct Ball_Data
{
	float	m_lifeTime;

	Vector2 m_pos;

	Vector2	m_direction;

	float	m_speed;
};

class Ball
{
public:

	Ball_Data m_data;
	Sprite* m_sprite;

	std::chrono::steady_clock::time_point m_creationTime;
	std::chrono::duration<float> m_currentLifeTime;

	Ball() { };
	~Ball();

	void InitBall(float lifeTime, Vector2 startPos, Vector2 direction, float speed, Texture* texture);
	void Move();
};

