#pragma once
#include "Window.h"

#ifdef SFML_STATIC
class WindowSFML : public Window
{
public:

	sf::RenderWindow* m_window;

	WindowSFML() { };
	~WindowSFML() { };

	void InitWindow(HINSTANCE hInstance, int nCmdShow, int width, int height) override;
};
#endif
