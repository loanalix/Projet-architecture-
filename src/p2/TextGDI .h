#pragma once

#ifdef _GDI

#include "Text.h"
#include <Windows.h>

class TextGDI : public Text
{
public:
	
	HDC m_hdc;

	TextGDI(HDC hdc) : m_hdc(hdc) {}

	void SetText(const std::string& text) override;
	void SetPosition(int x, int y) override;
	void  Draw() override;
};

#endif

