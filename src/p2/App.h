#pragma once
#include "iostream"
#include "vector"

class Window;
class Graphics;
class Factory;
class Texture;
class Ball;
class Timer;

class App
{
private:

	static App* m_instance;
	Window* m_window;
	Graphics* m_graphics;
	Timer* m_timer;



public:

	App() { };
	~App();

	bool m_appRunning;
	Texture* m_renderTexture;
	Texture* m_texture;
	std::vector<Ball*> m_vBall;
	Factory* m_factory;

	static App* GetInstance();
	Window* GetWindow();
	Graphics* GetGraphics();

	void InitApp(HINSTANCE hInstance, int nCmdShow, int width, int height);
	void MessageLoop();
	
};

