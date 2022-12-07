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
			std::cout << "Sprite not loaded in!";
			return;
		}
		sprite.setTexture(texture);
	}

	void Sprite::SetPosition(const sf::Vector2f& position)
	{
		sprite.setPosition(position);
	}
	void Sprite::SetTransparency(const sf::Uint8& aplha)
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