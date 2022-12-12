#pragma once
#ifndef TURN_MANAGER_h
#define TURN_MANAGER_h
#include "Globals.h"
#include "Entity.h"
#include "Text.h"
#include "Piece.h"
#include "TopLeftPanel.h"
namespace TicTacToe
{
	class TurnManager : public TopLeftPanel // Shows the current turn if it's X's or O's turn
	{
	public:
		TurnManager();
		~TurnManager();
		static TurnManager& Instance();
		void Reset() override;
		Piece::PieceType GetCurrentTurn();
		void SetNextTurn();
		void SetNoTurn();
	private:
		static const char* CURRENT_TURN_TEXT;
	};
}
#endif
