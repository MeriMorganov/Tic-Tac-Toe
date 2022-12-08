#include "Button.h"
namespace Commons
{
	Button::Button()
	{
		buttonSpriteStates = std::shared_ptr<Commons::Sprite[]>(new Commons::Sprite[ButtonState_Max]());
	}
	Button::~Button()
	{
	}
	void Button::SetPosition(const sf::Vector2f& position)
	{
		for (int i = 0; i < ButtonState_Max; i++)
		{
			buttonSpriteStates[i].SetPosition(sf::Vector2f(position.x, position.y));
		}
		buttonText->SetPosition(sf::Vector2f(position.x + leftTextPadding, position.y + topTextPadding));
	}
	void Button::SetSprite(ButtonState buttonState, std::string filePath)
	{
		switch (buttonState)
		{
		case ButtonState_Default:
			buttonSpriteStates[ButtonState_Default].SetSprite(filePath);
			break;
		case ButtonState_Hover:
			buttonSpriteStates[ButtonState_Hover].SetSprite(filePath);
			break;
		case ButtonState_Clicked:
			buttonSpriteStates[ButtonState_Clicked].SetSprite(filePath);
			break;
		}
	}
	void Button::SetText(std::string text, std::string fontPath)
	{
		buttonText->SetText(text);
		buttonText->SetFont(fontPath);
	}

	void Button::SetLeftTextPadding(const float &padding)
	{
		leftTextPadding = padding;
	}
	void Button::SetTopTextPadding(const float &padding)
	{
		topTextPadding = padding;
	}

	void Button::SetButtonState(ButtonState buttonState)
	{
		currentButtonState = buttonState;
	}
	sf::FloatRect Button::GetGlobalBounds()
	{
		return buttonSpriteStates[ButtonState_Default].GetGlobalBounds();
	}
	void Button::Draw()
	{
		switch (currentButtonState)
		{
		case ButtonState_Default:
			buttonSpriteStates[ButtonState_Default].Draw();
			break;
		case ButtonState_Hover:
			buttonSpriteStates[ButtonState_Hover].Draw();
			break;
		case ButtonState_Clicked:
			buttonSpriteStates[ButtonState_Clicked].Draw();
			break;
		}

		buttonText->Draw();
	}
	bool Button::IsClicked(sf::Event& event)
	{
		if (Commons::InputManager::Instance().IsLeftMouseDown(event))
		{
			sf::FloatRect bounds = GetGlobalBounds();
			bool clicked =  bounds.contains(Commons::AppWindow::Instance().GetMousePos());
			if (clicked)
			{
				SetButtonState(ButtonState_Clicked);
				return clicked;
			}
		}
		return false;
	}

	bool Button::IsHovering(sf::Event& event)
	{
		sf::FloatRect bounds = GetGlobalBounds();
		bool hovering = bounds.contains(Commons::AppWindow::Instance().GetMousePos());

		if (hovering)
		{
			SetButtonState(ButtonState_Hover);
		}
		else
		{
			SetButtonState(ButtonState_Default);
		}
		return false;
	}

	void Button::UpdateState(sf::Event& event)
	{
		if (IsClicked(event))
		{
			//TODO: convert to event 
		}
		else if (IsHovering(event))
		{
			//TODO: convert to event 
		}
	}
}