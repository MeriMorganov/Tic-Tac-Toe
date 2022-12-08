#pragma once
#ifndef BUTTON_h
#define BUTTON_h
#include "SFMLWrapper.h"
#include "InputManager.h"
#include "Sprite.h"
#include "Text.h"
namespace Commons
{
	class Button : SFMLWrapper
	{
	public:
		enum ButtonState
		{
			ButtonState_Default = 0,
			ButtonState_Hover,
			ButtonState_Clicked,
			ButtonState_Max
		};
		Button();
		~Button();
		virtual void SetPosition(const sf::Vector2f& position) override;
		virtual void SetSprite(ButtonState buttonState, std::string filePath);
		virtual void SetText(std::string text, std::string fontPath);
		virtual void SetLeftTextPadding(const float& padding);
		virtual void SetTopTextPadding(const float& padding);
		void SetButtonState(ButtonState buttonState);
		virtual sf::FloatRect GetGlobalBounds() override;
		virtual void Draw() override;
		bool IsClicked(sf::Event& event);
		bool IsHovering(sf::Event& event);
		void UpdateState(sf::Event& event);

	private:
		ButtonState currentButtonState = ButtonState_Default;
		std::shared_ptr<Commons::Sprite[]> buttonSpriteStates;
		std::shared_ptr <Commons::Text> buttonText = std::make_shared<Commons::Text>();
		float leftTextPadding = 0.0f;
		float topTextPadding = 0.0f;
	};
}
#endif
