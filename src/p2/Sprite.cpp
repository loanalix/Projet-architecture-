#include "pch.h"
#include "Sprite.h"
using namespace maths;

void Sprite::InitSprite(Texture* texture, Vector2 startPos)
{
	m_texture = texture;
	m_pos = startPos;
}