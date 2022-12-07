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
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (event.type == sf::Event::MouseButtonPressed && mouseDown == false)
			{
				mouseDown = true;
				return true;
			}
			if (mouseDown == true)
			{
				if (event.type == sf::Event::MouseButtonReleased)
				{
					mouseDown = false;
				}
			}
		}

		return false;
	}
}