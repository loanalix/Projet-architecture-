#pragma once

class Window
{
public:

	int			m_width;
	int			m_height;
	int			m_nCmdShow;
	HINSTANCE	m_hInstance;
	HWND		m_hWnd;


	Window() { };
	~Window() { };

	void virtual InitWindow(HINSTANCE hInstance,int nCmdShow, int width, int height);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void RegisterWindow();

};

