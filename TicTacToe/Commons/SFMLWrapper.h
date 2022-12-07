#pragma once
#ifndef SFML_WRAPPER_h
#define SFML_WRAPPER_h
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AppWindow.h"
#include "Vector2D.h"
namespace Commons
{
	class SFMLWrapper
	{
		virtual void SetPosition(const sf::Vector2f& position);
		virtual sf::FloatRect GetGlobalBounds();
		virtual void Draw();
	};
}
#endif
