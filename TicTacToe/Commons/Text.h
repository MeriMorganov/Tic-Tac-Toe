#pragma once
#ifndef TEXT_h
#define TEXT_h
#include "SFMLWrapper.h"
namespace Commons
{
	class Text : SFMLWrapper // Simple sprite base class to place text on the screen easily
	{
	public:
		Text();
		~Text();
		void SetFont(const std::string& filePath);
		void SetText(const std::string& str);
		void SetPosition(const Vector2D<float>& position) override;
		void Draw() override;
	private:
		sf::Text text;
		sf::Font font;
	};
}
#endif
