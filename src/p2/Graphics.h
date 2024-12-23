#pragma once

class Texture;
class Sprite;

class Graphics
{
public:
	HDC memHdc;
	Graphics() { };
	~Graphics() { };

	void virtual InitGraphics() { };
	void virtual Render(Texture* renderTexture, Sprite* sprite) { };
	void virtual RenderToWindow(HDC hDC, Texture* renderTexture) { };
	//void virtual DrawTextInWindow(const std::string& text, int x, int y);
};

