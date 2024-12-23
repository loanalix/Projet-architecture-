#include "pch.h"

#ifdef _GDI
#include "WindowGDI.h"


void WindowGDI::InitWindow(HINSTANCE hInstance, int nCmdShow, int width, int height)
{
	Window::InitWindow(hInstance, nCmdShow, width, height);

	m_hWnd = CreateWindowW(L"WinAppClass", L"Title", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, m_width, m_height, nullptr, nullptr, m_hInstance, nullptr);

	ShowWindow(m_hWnd, nCmdShow);
	UpdateWindow(m_hWnd);
}

WindowGDI::~WindowGDI()
{

}
#endif