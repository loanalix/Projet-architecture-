#include "pch.h"
#include "TextureGDI.h"
#include "Window.h"
#include "App.h"

void TextureGDI::InitRenderTexture()
{
    Window* window = App::GetInstance()->GetWindow();
    HDC hdc = GetDC(window->m_hWnd);

    m_hBitmap = CreateCompatibleBitmap(hdc, window->m_width, window->m_height);

    m_width = window->m_width;
    m_height = window->m_height;

    ReleaseDC(window->m_hWnd, hdc);

}

void TextureGDI::InitTexture(const char* path)
{
    Window* window = App::GetInstance()->GetWindow();
    LoadTexture(path); 
    
    BITMAPINFOHEADER infoHeader;
    infoHeader.biSize = sizeof(BITMAPINFOHEADER) ;
    infoHeader.biWidth = m_width;
    infoHeader.biHeight = m_height;
    infoHeader.biBitCount = 32;
    infoHeader.biCompression = 0;


    HDC hdc = GetDC(window->m_hWnd);
    m_hBitmap = CreateDIBitmap(hdc, &infoHeader, CBM_INIT, m_colorBuffer, (BITMAPINFO*)&infoHeader, DIB_RGB_COLORS);

    ReleaseDC(window->m_hWnd, hdc);
}

void TextureGDI::LoadTexture(const char* path)
{
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    FILE* pfile;
    fopen_s(&pfile, path, "rb");

    if (pfile == nullptr)
    {
        return;
    }


    fread(&fileHeader, 1, sizeof(BITMAPFILEHEADER), pfile);
    fread(&infoHeader, 1, sizeof(BITMAPINFOHEADER), pfile);

    m_lSize = fileHeader.bfSize;// -sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER);
    BYTE* buffer = new BYTE[m_lSize];

    if (buffer == nullptr)
    {
        fclose(pfile);
        return;
    }

    fseek(pfile, 0, SEEK_SET);
    size_t result = fread(buffer, 1, m_lSize, pfile);
    fclose(pfile);

    if (result != m_lSize)
    {
        delete[] buffer;
        return;
    }


    m_lSize = infoHeader.biWidth * infoHeader.biHeight * 4;

    BYTE* bgr = buffer + fileHeader.bfOffBits;
    m_colorBuffer = BgrToBgra(bgr, infoHeader.biWidth, abs(infoHeader.biHeight));
    delete[] buffer;

    m_width = infoHeader.biWidth;
    m_height = infoHeader.biHeight;

    return;
}

TextureGDI::~TextureGDI()
{
    delete m_colorBuffer;
}