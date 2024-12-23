#include "pch.h"
#include "Ball.h"
#include "Sprite.h"
#include "App.h"
#include "Window.h"
#include "Texture.h"
#include <chrono>

void Ball::InitBall(float lifeTime, Vector2 startPos, Vector2 direction, float speed, Texture* texture)
{
	m_sprite = new Sprite();
	m_sprite->InitSprite(texture, startPos);

	m_data.m_lifeTime = lifeTime;
	m_data.m_pos = startPos;
	m_data.m_direction = direction;
	m_data.m_speed = speed;

	VectorNoramlise(&m_data.m_direction);
	
	m_creationTime = std::chrono::steady_clock::now();
}

void Ball::Move()
{
	m_data.m_pos.x += m_data.m_direction.x * m_data.m_speed;
	m_data.m_pos.y += m_data.m_direction.y * m_data.m_speed ;

	if (m_data.m_pos.x < 0 || m_data.m_pos.x > App::GetInstance()->GetWindow()->m_width - m_sprite->m_texture->m_width)
		m_data.m_direction.x = -m_data.m_direction.x;
	if (m_data.m_pos.y < 0 || m_data.m_pos.y > App::GetInstance()->GetWindow()->m_height - m_sprite->m_texture->m_height)
		m_data.m_direction.y = -m_data.m_direction.y;

	m_sprite->m_pos = m_data.m_pos;
	VectorNoramlise(&m_data.m_direction);

	auto currentTime = std::chrono::steady_clock::now();
	m_currentLifeTime = currentTime - m_creationTime;
}

Ball::~Ball()
{
	delete m_sprite;
}
