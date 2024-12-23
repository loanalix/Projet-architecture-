#include "pch.h"

#ifdef SFML_STATIC

#include "WindowSFML.h"


void WindowSFML::InitWindow(HINSTANCE hInstance, int nCmdShow, int width, int height)
{
	Window::InitWindow(hInstance, nCmdShow, width, height);

	m_hWnd = CreateWindowW(L"WinAppClass", L"Title", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, m_width, m_height, nullptr, nullptr, m_hInstance, nullptr);
	if ( m_hWnd==NULL )
		return;
	m_window = new sf::RenderWindow(m_hWnd);
}
#endif