#include "InputManager.h"
namespace Commons
{
	InputManager& InputManager::Instance()
	{
		static InputManager INSTANCE;
		return INSTANCE;
	}
	bool InputManager::IsLeftMouseClick(const sf::Event& event)
	{
		if (IsLeftMouseDown(event) && mouseDown == false)
		{
			mouseDown = true;
			return true;
		}
		if (mouseDown == true && IsLeftMouseReleased(event))
		{
			mouseDown = false;
		}
		return false;
	}
	bool InputManager::IsLeftMouseDown(const sf::Event& event)
	{
		return event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left;
	}
	bool InputManager::IsLeftMouseReleased(const sf::Event& event)
	{
		return event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left;
	}
}