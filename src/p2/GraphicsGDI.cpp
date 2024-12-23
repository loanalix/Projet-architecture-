#include "pch.h"

#ifdef _GDI
#include "GraphicsGDI.h"
#include "App.h"
#include "WindowGDI.h"
#include "TextureGDI.h"
#include "Sprite.h"


void GraphicsGDI::InitGraphics()
{
	HDC hdc = GetDC(App::GetInstance()->GetWindow()->m_hWnd);
	HDC memHdc = CreateCompatibleDC(hdc);
    DeleteDC(memHdc);
    ReleaseDC(App::GetInstance()->GetWindow()->m_hWnd, hdc);
}

void GraphicsGDI::Render(Texture* renderTexture, Sprite* sprite)
    {
        HDC hdc = GetDC(App::GetInstance()->GetWindow()->m_hWnd);
        HDC memHdc = CreateCompatibleDC(hdc);
        HDC hDcSprite = CreateCompatibleDC(hdc);

        HBITMAP oldBmp = (HBITMAP)SelectObject(memHdc, renderTexture->m_hBitmap);
    
        SelectObject(hDcSprite, sprite->m_texture->m_hBitmap);

        BLENDFUNCTION blendFunction;
        blendFunction.BlendOp = AC_SRC_OVER;
        blendFunction.BlendFlags = 0;
        blendFunction.SourceConstantAlpha = 255;
        blendFunction.AlphaFormat = AC_SRC_ALPHA;


        BOOL test = AlphaBlend(
            memHdc,
            sprite->m_pos.x, sprite->m_pos.y,
            sprite->m_texture->m_width, sprite->m_texture->m_height,
            hDcSprite,
            0, 0,
            sprite->m_texture->m_width, sprite->m_texture->m_height,
            blendFunction);
        SelectObject(memHdc, oldBmp);

        DeleteDC(memHdc);
        DeleteDC(hDcSprite);
        ReleaseDC(App::GetInstance()->GetWindow()->m_hWnd, hdc);
    }

    void GraphicsGDI::RenderToWindow(HDC hDC, Texture* renderTexture)
    {

        HDC memHdc = CreateCompatibleDC(hDC);

        HBITMAP oldBmp = (HBITMAP)SelectObject(memHdc, renderTexture->m_hBitmap);
     
        BitBlt(hDC,
            0, 0,
            renderTexture->m_width, renderTexture->m_height,
            memHdc,
            0, 0, SRCCOPY);

        PatBlt(memHdc, 0, 0, App::GetInstance()->GetWindow()->m_width, App::GetInstance()->GetWindow()->m_height, PATCOPY);

        SelectObject(memHdc, oldBmp);

        DeleteDC(memHdc);

    }

//void GraphicsGDI::DrawTextGDI(const std::string& text, int x, int y)
//{
//    HDC hdc = GetDC(App::GetInstance()->GetWindow()->m_hWnd);
//    TextGDI textGDI(hdc);
//    textGDI.SetText(text);
//    textGDI.SetPosition(x, y);
//    textGDI.Draw();
//    ReleaseDC(App::GetInstance()->GetWindow()->m_hWnd, hdc);
//}


#endif