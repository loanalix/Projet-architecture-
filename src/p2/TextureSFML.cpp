#include "pch.h"
#include "TextureSFML.h"
#include "App.h"
#include "Window.h"

#ifdef SFML_STATIC

void TextureSFML::InitTexture(const char* path)
{
    m_texture = new sf::Texture();

	LoadTexture(path);

    if (!m_texture->create(m_width, m_height))
    {
        return;
    }
    m_texture->update(m_colorBuffer, m_width, m_height, 0, 0);
}

void TextureSFML::InitRenderTexture()
{
    m_renderTexture = new sf::RenderTexture();

	Window* window = App::GetInstance()->GetWindow();
	m_renderTexture->create(window->m_width, window->m_height);
}

void TextureSFML::LoadTexture(const char* path)
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
    m_colorBuffer = BgraToRgba(m_colorBuffer, infoHeader.biWidth, abs(infoHeader.biHeight));
    delete[] buffer;

    m_width = infoHeader.biWidth;
    m_height = infoHeader.biHeight;

    return;
}

TextureSFML::~TextureSFML()
{
    delete m_renderTexture;
    delete m_texture;
}

#endif