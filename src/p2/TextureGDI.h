#pragma once
#include "Texture.h"

class TextureGDI : public Texture
{
public:
	
	TextureGDI() { };
	~TextureGDI();

	void InitTexture(const char* path) override;
	void InitRenderTexture() override;

	void LoadTexture(const char* path) override;

};

