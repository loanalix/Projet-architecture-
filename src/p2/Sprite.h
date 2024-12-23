#pragma once

#include "Ball.h"
#include "Math.h"

using namespace maths;

using namespace maths;

class Texture;

class Sprite
{

public:
	Vector2 m_pos; 

	Texture* m_texture;

	Sprite() { };
	~Sprite() { };

	void InitSprite(Texture* m_texture, Vector2 startPos);

};

