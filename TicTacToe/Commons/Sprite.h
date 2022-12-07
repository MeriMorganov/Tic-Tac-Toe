#pragma once
#ifndef SPRITE_h
#define SPRITE_h
#include "SFMLWrapper.h"
namespace Commons
{
	class Sprite : SFMLWrapper
	{
	public:
		Sprite();
		~Sprite();

		void SetSprite(const std::string& filePath);
		void SetPosition(const sf::Vector2f& position) override;
		void SetTransparency(const sf::Uint8& aplha); //255 = max
		sf::FloatRect GetGlobalBounds() override;
		void Draw() override;

	private:
		sf::Texture texture;
		sf::Sprite sprite;
	};
}
#endif
