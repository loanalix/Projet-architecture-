#pragma once

#include <chrono>

class Timer
{
private:
    std::chrono::time_point<std::chrono::steady_clock> m_startTime;
    std::chrono::time_point<std::chrono::steady_clock> m_lastFrameTime;
    int m_frameCount;
    float m_fps;

public:
    Timer();

    void Start();  // D�marrer le chronom�tre
    void Update(); // Mettre � jour les FPS
    float GetFPS() const; // Obtenir le FPS actuel
    float GetElapsedTime() const; // Temps �coul� depuis le d�but en secondes
    bool IsTimeToCreateObject(float intervalInSeconds); // V�rifie si l'intervalle de cr�ation est d�pass�
};
