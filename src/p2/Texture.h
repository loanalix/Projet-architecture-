#pragma once

class Window;

class Texture
{
public:

	HBITMAP				m_hBitmap;
	
	BYTE*				m_colorBuffer;
	long				m_lSize; // w * h *4
	int					m_width;
	int					m_height;

	Texture() { };
	~Texture() { };

	void virtual InitTexture(const char* path) { };
	void virtual InitRenderTexture() { };

	static BYTE* BgrToBgra(BYTE* bgr, int width, int height);
	static BYTE* BgraToRgba(BYTE* bgra, int width, int height);

	void virtual LoadTexture(const char* path);

};

