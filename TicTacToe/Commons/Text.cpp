#include "Text.h"
namespace Commons
{
	Text::Text()
	{

	}
	Text::~Text()
	{

	}
	void Text::SetFont(const sf::String& filePath)
	{
		if (!font.loadFromFile(filePath))
		{
			std::cout << "Font not loaded in!";
			return;
		}
		text.setFont(font);
	}
	void Text::SetText(const sf::String& str)
	{
		text.setString(str);
	}
	void Text::SetPosition(const sf::Vector2f& position)
	{
		text.setPosition(position);
	}
	void Text::Draw()
	{
		Commons::AppWindow::Instance().Draw(text);
	}
}