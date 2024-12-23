#include "pch.h"
#include "main.h"
#include "WindowGDI.h"
#include "App.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{	

	App::GetInstance()->InitApp(hInstance, nCmdShow, 1000, 800);
	App::GetInstance()->MessageLoop();


#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}
