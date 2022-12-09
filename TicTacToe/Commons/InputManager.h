#pragma once
#ifndef INPUT_MANAGER_h
#define INPUT_MANAGER_h
#include <SFML/Graphics.hpp>
namespace Commons
{
	class InputManager // Information on current user input
	{
	public:
		static InputManager& Instance();
		bool IsLeftMouseClick(const sf::Event& event); // One whole mouse click instead of just down or release
		bool IsLeftMouseDown(const sf::Event& event);
		bool IsLeftMouseReleased(const sf::Event& event);

	private:
		bool mouseDown;
	};
}
#endif
