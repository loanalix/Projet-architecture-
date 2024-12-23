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

    void Start();  // Démarrer le chronomètre
    void Update(); // Mettre à jour les FPS
    float GetFPS() const; // Obtenir le FPS actuel
    float GetElapsedTime() const; // Temps écoulé depuis le début en secondes
    bool IsTimeToCreateObject(float intervalInSeconds); // Vérifie si l'intervalle de création est dépassé
};
