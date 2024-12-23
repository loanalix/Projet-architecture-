#pragma once

class Window;
class Texture;
class Graphics;

class Factory
{
public:
	Factory() { };
	~Factory() { };

	Window* CreateNewWindow();
	Graphics* CreateGraphics();
	Texture* CreateTexture();

};

