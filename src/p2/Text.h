#pragma once

#include <string>

class Window;

class Text
{
public:
    std::string m_text;
    int m_x;
    int m_y;

    Text() { };

    virtual ~Text() { };

    virtual void SetText(const std::string& text) = 0;
    virtual void SetPosition(int x, int y) = 0;
    virtual void Draw() ;
    

};

