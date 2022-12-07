#pragma once
#ifndef APP_WINDOW_h
#define APP_WINDOW_h
#include <SFML/Graphics.hpp>

namespace Commons
{
	class AppWindow // Wrapper for window related functions for SFML or other 3rd party sources.
	{
	public:
		AppWindow();
		~AppWindow();
		static const char* WINDOW_NAME;
		static const int WINDOW_WIDTH = 960;
		static const int WINDOW_HEIGHT = 540;
		static AppWindow& Instance();
		sf::Vector2f GetMousePos();
		bool IsOpen();
		bool PollEvent(sf::Event& event);
		void Draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
		void Close();
		void Clear();
		void Display();
	private:
		sf::RenderWindow renderWindow{ sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME }; //Note: Cannot be saved into another variable
	};
}
#endif