#include "pch.h"

#ifdef SFML_STATIC
#include "GraphicsSFML.h"
#include "WindowSFML.h"
#include "TextureSFML.h"
#include "Sprite.h"
#include "App.h"
#include "TextSFML .h"

void GraphicsSFML::InitGraphics()
{

}

void GraphicsSFML::Render(Texture* renderTexture, Sprite* sprite)
{
	TextureSFML* render = reinterpret_cast<TextureSFML*>(renderTexture);
	TextureSFML* sfTexture = reinterpret_cast<TextureSFML*>(sprite->m_texture);

	sf::Sprite* sfSprite = new sf::Sprite();
	sfSprite->setTexture(*sfTexture->m_texture);
	sfSprite->setPosition(sprite->m_pos.x, sprite->m_pos.y);
	
	render->m_renderTexture->draw(*sfSprite);

	delete sfSprite;
}

void GraphicsSFML::RenderToWindow(HDC hDC, Texture* renderTexture)
{
	WindowSFML* window = reinterpret_cast<WindowSFML*>(App::GetInstance()->GetWindow());
	window->m_window->clear();

	TextureSFML* render = reinterpret_cast<TextureSFML*>(renderTexture);
	render->m_renderTexture->display();

	sf::Sprite* sfSprite = new sf::Sprite();
	sfSprite->setTexture(render->m_renderTexture->getTexture());


	window->m_window->draw(*sfSprite);
	window->m_window->display();
	render->m_renderTexture->clear(sf::Color(255, 255, 255, 255));

	delete sfSprite;
}


//void GraphicsSFML::DrawTextInWindow(const std::string& text, int x, int y)
//{
//	WindowSFML* window = reinterpret_cast<WindowSFML*>(App::GetInstance()->GetWindow());
//	TextSFML textSFML(window->m_window);
//	textSFML.SetText(text);
//	textSFML.SetPosition(x, y);
//	textSFML.Draw();
//}

#endif