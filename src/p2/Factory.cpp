#include "pch.h"
#include "Factory.h"
#include "WindowGDI.h";
#include "WindowSFML.h";
#include "GraphicsGDI.h";
#include "GraphicsSFML.h";
#include "TextureGDI.h";
#include "TextureSFML.h";

Window* Factory::CreateNewWindow()
{
#ifdef _GDI
	return new WindowGDI();
#endif
#ifdef SFML_STATIC
	return new WindowSFML();
#endif
}

Graphics* Factory::CreateGraphics()
{
#ifdef _GDI
	return new GraphicsGDI();
#endif
#ifdef SFML_STATIC
	return new GraphicsSFML();
#endif
}

Texture* Factory::CreateTexture()
{
#ifdef _GDI
	return new TextureGDI();
#endif
#ifdef SFML_STATIC
	return new TextureSFML();
#endif
}
