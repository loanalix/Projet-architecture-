#pragma once
#ifdef SFML_STATIC

#include "Graphics.h"

class GraphicsSFML: public Graphics
{
public:
	GraphicsSFML() { };
	~GraphicsSFML() { };

	void InitGraphics() override;
	void Render(Texture* renderTexture, Sprite* sprite) override;
	void RenderToWindow(HDC hDC, Texture* renderTexture)  override;
	//void  DrawTextInWindow(const std::string& text, int x, int y)override;
};
#endif
