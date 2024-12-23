#pragma once

#ifdef _GDI

#include "Window.h"

class WindowGDI : public Window
{
public:

	WindowGDI() { };
	~WindowGDI();

	void InitWindow(HINSTANCE hInstance, int nCmdShow, int width, int height) override;
	
};
#endif
