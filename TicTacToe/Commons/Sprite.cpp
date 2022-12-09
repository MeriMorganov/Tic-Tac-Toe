#include "Sprite.h"
namespace Commons
{
	Sprite::Sprite()
	{

	}
	Sprite::~Sprite()
	{

	}

	void Sprite::SetSprite(const std::string& filePath)
	{
		if (!texture.loadFromFile(filePath))
		{
			DebugMsg::LogErrorMsg("Sprite not lodaed in!");
			return;
		}
		sprite.setTexture(texture);
	}

	void Sprite::SetPosition(const Vector2D<float>& position)
	{
		sprite.setPosition(sf::Vector2f(position.x,position.y));
	}
	void Sprite::SetTransparency(const unsigned char& aplha)
	{
		sf::Color currentColor = sprite.getColor();
		sprite.setColor(sf::Color(currentColor.r, currentColor.g, currentColor.b, aplha));
	}
	sf::FloatRect Sprite::GetGlobalBounds()
	{
		return sprite.getGlobalBounds();
	}
	void Sprite::Draw()
	{
		Commons::AppWindow::Instance().Draw(sprite);
	}
}