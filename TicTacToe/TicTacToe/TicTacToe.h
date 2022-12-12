#pragma once
#ifndef TIC_TAC_TOE_h
#define TIC_TAC_TOE_h
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFMLWrapper.h"
#include "AppWindow.h"
#include "RestartButton.h"
#include "Grid.h"
#include "TurnManager.h"
#include "WinnerBoard.h"
#include "ScoreBoard.h"
namespace TicTacToe
{
	class TicTacToe // Main class for the game
	{
	public:

		TicTacToe();
		~TicTacToe();
		static TicTacToe& Instance();
		void Update();
		void Draw();
		void Reset();
	private:
		std::unique_ptr<Grid> grid = std::make_unique<Grid>();
		std::unique_ptr<RestartButton> restartButton = std::make_unique<RestartButton>();
	};
}
#endif
