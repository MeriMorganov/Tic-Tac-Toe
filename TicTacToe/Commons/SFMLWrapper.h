#pragma once
#ifndef SFML_WRAPPER_h
#define SFML_WRAPPER_h
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AppWindow.h"
#include "Vector2D.h"
#include "DebugMsg.h"
#include "NotImplementedException.h"
namespace Commons
{
	class SFMLWrapper // Wrapper for the 3rd party SFML classes. 
	{
		public:
			virtual void SetPosition(const Vector2D<float>& position);
			virtual sf::FloatRect GetGlobalBounds();
			virtual void Draw();
	};
}
#endif
