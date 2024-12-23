#include "pch.h"
#include "App.h"
#include "Window.h"
#include "Graphics.h"
#include "Texture.h"
#include "Factory.h"
#include "Math.h"
#include "Ball.h"
#include <chrono> 
#include "Timer.h"

using namespace std::chrono;
using namespace maths;

App* App::m_instance = nullptr;

App* App::GetInstance() {
    if (m_instance == nullptr) {
        m_instance = new App();
    }
    return m_instance;
}

Window* App::GetWindow()
{
    return m_window;
}

Graphics* App::GetGraphics()
{
    return m_graphics;
}

void App::InitApp(HINSTANCE hInstance, int nCmdShow, int width, int height)
{

    m_window = m_factory->CreateNewWindow();
    m_graphics = m_factory->CreateGraphics();

    m_window->InitWindow(hInstance, nCmdShow, width, height);

    m_texture = m_factory->CreateTexture();
    m_texture->InitTexture("../../../ball.bmp");

    m_renderTexture = m_factory->CreateTexture();
    m_renderTexture->InitRenderTexture();



    m_appRunning = true;

    m_factory = new Factory();
    m_graphics->InitGraphics();

    m_timer = new Timer();
    m_timer->Start();

}

void App::MessageLoop()
{
    auto lastTime = steady_clock::now();

    Vector2 pos;
    pos.x = 100;
    pos.y = 100;
    Vector2 dir;
    dir.x = 3;
    dir.y = 1;


    m_vBall.push_back(new Ball());
    m_vBall.back()->InitBall(9.0f, pos, dir, 0.5f, m_texture);

    while (m_appRunning)
    {

        auto currentTime = steady_clock::now();
        duration<double> elapsedTime = currentTime - lastTime;
    
        if (elapsedTime.count() >= 2.0) 
        {

            m_vBall.push_back(new Ball());
            m_vBall.back()->InitBall(9.0f, pos, dir, 0.5f, m_texture);

            lastTime = currentTime; 
        }

        for (int i = 0; i < m_vBall.size(); i++)
        {
            if (m_vBall[i]->m_currentLifeTime.count() >= m_vBall[i]->m_data.m_lifeTime)
            {
                delete m_vBall[i];
                m_vBall.erase(m_vBall.begin() + i);
            }

            m_vBall[i]->Move();

        }

        MSG msg;

        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) 
        {
            msg.message;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            msg.message;
        }

        m_timer->Update();

        InvalidateRect(m_window->m_hWnd, nullptr, FALSE);
    }
}

App::~App()
{
    delete m_factory;
    delete m_texture;
    delete m_window;
    delete m_graphics;
    delete m_instance;
}