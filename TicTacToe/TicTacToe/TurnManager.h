#pragma once
#ifndef TURN_MANAGER_h
#define TURN_MANAGER_h
#include "Globals.h"
#include "Entity.h"
#include "Text.h"
#include "Piece.h"
namespace TicTacToe
{
	class TurnManager : Commons::Entity // Shows the current turn if it's X's or O's turn
	{
	public:
		TurnManager();
		~TurnManager();
		static TurnManager& Instance();
		void Reset() override;
		void SetPosition(const Commons::Vector2D<float>& position) override;
		void Draw() override;
		Piece::PieceType GetCurrentTurn();
		void SetNextTurn();
		void SetNoTurn();
	private:
		static const float CURRENT_TURN_POS_X;
		static const float CURRENT_TURN_POS_Y;
		static const float CURRENT_TURN_PIECE_OFFSET_X;
		static const float CURRENT_TURN_PIECE_OFFSET_Y;

		static const char* CURRENT_TURN_TEXT;

		std::unique_ptr <Commons::Text> text = std::make_unique<Commons::Text>();
		std::unique_ptr <Piece> currentTurnPiece = std::make_unique<Piece>();
	};
}
#endif
