#include "pch.h"


#ifdef _GDI
#include"TextGDI .h"
#include "Window.h"
#include "App.h"

void TextGDI::SetText(const std::string& text)
{
	m_text = text;
}

void TextGDI::SetPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}
void TextGDI::Draw()
{

	TextOutA(m_hdc, m_x, m_y, m_text.c_str(), m_text.size());
}


#endif