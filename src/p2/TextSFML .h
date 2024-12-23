#pragma once

#ifdef SFML_STATIC

#include "Text.h"

class TextSFML: public Text
{
public:
	sf::RenderWindow* m_window;  // Pointeur vers la fen�tre SFML
	sf::Font m_font;             // Font utilis�e pour le texte
	sf::Text m_sfText;           // Objet texte SFML

	TextSFML() { };
	~TextSFML() { };

	void SetText(const std::string& text) override;
	void SetPosition(int x, int y) override;
	void  Draw() override;

};
#endif

