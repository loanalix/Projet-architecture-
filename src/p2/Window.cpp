#include "pch.h"
#include "Window.h"
#include "Graphics.h"
#include "App.h"

// --TEMPORAIRE-- //
#include "Texture.h"
#include "TextureSFML.h"
#include "Factory.h"
#include "Sprite.h"	
#include "Ball.h"
#include "Math.h"	
#include <string>
using namespace maths;
// -------------- //


void Window::InitWindow(HINSTANCE hInstance, int nCmdShow, int width, int height)
{
	m_hInstance = hInstance;
	m_width = width;
	m_height = height;

	RegisterWindow();


}

void Window::RegisterWindow()
{
	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInstance;
	wcex.hIcon = LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_APP));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"WinAppClass";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	if (RegisterClassExW(&wcex) == 0)
		return;
}

LRESULT Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	Window* pThis = reinterpret_cast<Window*>(App::GetInstance()->GetWindow());

	switch (message)
	{
	case WM_COMMAND:
	{
		int id = LOWORD(wParam);
		int notif = HIWORD(wParam);
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	case WM_PAINT:
	{

		if (App::GetInstance()->m_vBall.size() == 0)
		{
			break;
		}

		for (int i = 0; i < App::GetInstance()->m_vBall.size(); i++)
		{
			App::GetInstance()->GetGraphics()->Render(App::GetInstance()->m_renderTexture, App::GetInstance()->m_vBall[i]->m_sprite);
		}

		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		App::GetInstance()->GetGraphics()->RenderToWindow(hdc, App::GetInstance()->m_renderTexture);



		EndPaint(hWnd, &ps);

		break;
	}
	case WM_DESTROY:
	{
		App::GetInstance()->m_appRunning = false;
		PostQuitMessage(0);
		break;
	}
	default:
	{
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	}
	return 0;
}


