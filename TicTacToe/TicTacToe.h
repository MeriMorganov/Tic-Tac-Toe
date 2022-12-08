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
		TicTacToe();
		~TicTacToe();
		static TicTacToe& Instance();
		void Update();
		void Draw();
	private:
		std::unique_ptr<Grid> grid = std::make_unique<Grid>();
	};
}
#endif
