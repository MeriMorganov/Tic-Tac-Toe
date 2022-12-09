#include "Text.h"
namespace Commons
{
	Text::Text()
	{

	}
	Text::~Text()
	{

	}
	void Text::SetFont(const std::string& filePath)
	{
		if (!font.loadFromFile(filePath))
		{
			DebugMsg::LogErrorMsg("Font not loaded in!");
			return;
		}
		text.setFont(font);
	}
	void Text::SetText(const std::string& str)
	{
		text.setString(str);
	}
	void Text::SetPosition(const Vector2D<float>& position)
	{
		text.setPosition(sf::Vector2f(position.x,position.y));
	}
	void Text::Draw()
	{
		Commons::AppWindow::Instance().Draw(text);
	}
}