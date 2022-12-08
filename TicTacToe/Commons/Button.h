#pragma once
#ifndef BUTTON_h
#define BUTTON_h
#include "SFMLWrapper.h"
#include "InputManager.h";
#include "Sprite.h"
#include "Text.h"
namespace Commons
{
	class Button : SFMLWrapper
	{
	public:
		Button();
		~Button();
		virtual void SetPosition(const sf::Vector2f& position) override;
		virtual void SetSprite(std::string filePath);
		virtual void SetText(std::string text, std::string fontPath);
		virtual sf::FloatRect GetGlobalBounds() override;
		virtual void Draw() override;
		virtual bool IsClicked(sf::Event& event);

	private:
		std::shared_ptr <Commons::Sprite> buttonSprite = std::make_shared<Commons::Sprite>();
		std::shared_ptr <Commons::Text> buttonText = std::make_shared<Commons::Text>();
	};
}
#endif
