#pragma once
#ifndef TIC_TAC_TOE_h
#define TIC_TAC_TOE_h
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AppWindow.h"
#include "Grid.h"
#include "TurnManager.h"
namespace TicTacToe
{
	class TicTacToe
	{
	public:
		static void Launch();
		static void Draw();
	};
}
#endif
