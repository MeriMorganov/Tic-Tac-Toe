#pragma once
#ifndef BUTTON_h
#define BUTTON_h
#include "SFMLWrapper.h"
#include "InputManager.h"
#include "Sprite.h"
#include "Text.h"
namespace Commons
{
	class Button : SFMLWrapper // Simple button base class for quick button creation
	{
	public:
		enum ButtonState // Show a different sprite based on button state
		{
			ButtonState_Default = 0,
			ButtonState_Hover,
			ButtonState_Clicked,
			ButtonState_Max
		};
		Button();
		~Button();
		virtual void SetPosition(const Vector2D<float>& position) override;
		virtual void SetSprite(const ButtonState& buttonState, const std::string& filePath);
		virtual void SetText(const std::string& text, const std::string& fontPath);
		virtual void SetLeftTextPadding(const float& padding); // Add some padding from the left side to the text
		virtual void SetTopTextPadding(const float& padding); // Add some padding from the top side to the text
		void SetButtonState(ButtonState buttonState);
		virtual sf::FloatRect GetGlobalBounds() override;
		virtual void Draw() override;
		bool IsClicked(sf::Event& event);
		bool IsHovering(sf::Event& event);
		void UpdateState(sf::Event& event);

	private:
		ButtonState currentButtonState = ButtonState_Default;
		std::unique_ptr<Commons::Sprite[]> buttonSpriteStates;
		std::unique_ptr <Commons::Text> buttonText = std::make_unique<Commons::Text>();
		float leftTextPadding = 0.0f;
		float topTextPadding = 0.0f;
	};
}
#endif
