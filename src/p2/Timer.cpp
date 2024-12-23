#include "pch.h"

#include "Timer.h"  

Timer::Timer() : m_frameCount(0), m_fps(0.0f)
{
    m_startTime = std::chrono::steady_clock::now();
    m_lastFrameTime = m_startTime;
}

void Timer::Start()
{
    m_startTime = std::chrono::steady_clock::now();
    m_lastFrameTime = m_startTime;
}

void Timer::Update()
{
    auto currentFrameTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> frameDuration = currentFrameTime - m_lastFrameTime;
    m_lastFrameTime = currentFrameTime;

    m_fps = 1.0f / frameDuration.count();  
    m_frameCount++;
}

float Timer::GetFPS() const
{
    return m_fps;
}

float Timer::GetElapsedTime() const
{
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsedTime = currentTime - m_startTime;
    return elapsedTime.count();
}

bool Timer::IsTimeToCreateObject(float intervalInSeconds)
{
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> timeSinceLastObject = currentTime - m_lastFrameTime;

    return timeSinceLastObject.count() >= intervalInSeconds;
}