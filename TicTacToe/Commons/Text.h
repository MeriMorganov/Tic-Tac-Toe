#pragma once
#ifndef TEXT_h
#define TEXT_h
#include "SFMLWrapper.h"
namespace Commons
{
	class Text : SFMLWrapper
	{
	public:
		Text();
		~Text();
		void SetFont(const sf::String& filePath);
		void SetText(const sf::String& str);
		void SetPosition(const sf::Vector2f& position) override;
		void Draw() override;
	private:
		sf::Text text;
		sf::Font font;
	};
}
#endif
