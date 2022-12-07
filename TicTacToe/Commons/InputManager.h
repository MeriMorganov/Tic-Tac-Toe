#pragma once
#ifndef INPUT_MANAGER_h
#define INPUT_MANAGER_h
#include <SFML/Graphics.hpp>
namespace Commons
{
	class InputManager
	{
	public:
		static InputManager& Instance();
		bool IsLeftMouseClick(const sf::Event& event);

	private:
		bool mouseDown;
	};
}
#endif
