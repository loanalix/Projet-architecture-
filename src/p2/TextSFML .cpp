#include "pch.h"
#include"TextSFML .h"
#include "App.h"
#include "Window.h"

#ifdef SFML_STATIC

void TextSFML::SetText(const std::string& text)
{
	m_text = text;
}

void TextSFML::SetPosition(int x, int y)
{
	m_x = x;
	m_y = y;
	m_sfText.setPosition(static_cast<float>(m_x), static_cast<float>(m_y));
}

void TextSFML::Draw()
{

	m_window->draw(m_sfText);
}
#endif