#pragma once

#ifdef SFML_STATIC

#include "Texture.h"

class TextureSFML: public Texture
{
public:

	sf::Texture*			m_texture;
	sf::RenderTexture*		m_renderTexture;

	TextureSFML() { };
	~TextureSFML();

	void InitTexture(const char* path) override;
	void InitRenderTexture() override;
	void LoadTexture(const char* path) override;
};
#endif

