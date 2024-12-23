#pragma once

#ifdef _GDI
#include "Graphics.h"

class GraphicsGDI: public Graphics
{
public:

	//HDC hdc;
	
	//HDC hDcSprite;

	GraphicsGDI() { };
	~GraphicsGDI() { };

	void InitGraphics() override;
	void Render(Texture* renderTexture, Sprite* sprite) override;
	void RenderToWindow(HDC hDC, Texture* renderTexture)  override;
	//void  DrawTextInWindow(const std::string& text, int x, int y) override;

};
#endif