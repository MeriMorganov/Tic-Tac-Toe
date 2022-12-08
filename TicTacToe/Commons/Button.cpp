#include "Button.h"
namespace Commons
{
	Button::Button()
	{
	}
	Button::~Button()
	{
	}
	void Button::SetPosition(const sf::Vector2f& position)
	{
		buttonSprite->SetPosition(sf::Vector2f(position.x, position.y));
	}
	void Button::SetSprite(std::string filePath)
	{
		buttonSprite->SetSprite(filePath);
	}
	void Button::SetText(std::string text, std::string fontPath)
	{
		buttonText->SetText(text);
		buttonText->SetFont(fontPath);
	}
	sf::FloatRect Button::GetGlobalBounds()
	{
		return buttonSprite->GetGlobalBounds();
	}
	void Button::Draw()
	{
		buttonSprite->Draw();
	}
	bool Button::IsClicked(sf::Event& event)
	{
		if (Commons::InputManager::Instance().IsLeftMouseClick(event))
		{
			sf::FloatRect bounds = GetGlobalBounds();
			return bounds.contains(Commons::AppWindow::Instance().GetMousePos());
		}
		return false;
	}
}