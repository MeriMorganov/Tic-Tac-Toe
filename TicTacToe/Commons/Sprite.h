#pragma once
#ifndef SPRITE_h
#define SPRITE_h
#include "SFMLWrapper.h"
namespace Commons
{
	class Sprite : SFMLWrapper // Simple sprite base class to place an image on the screen easily
	{
	public:
		Sprite();
		~Sprite();

		void SetSprite(const std::string& filePath);
		void SetPosition(const Vector2D<float>& position) override;
		void SetTransparency(const unsigned char& aplha); //255 = max
		sf::FloatRect GetGlobalBounds() override;
		void Draw() override;

	private:
		sf::Texture texture;
		sf::Sprite sprite;
	};
}
#endif
