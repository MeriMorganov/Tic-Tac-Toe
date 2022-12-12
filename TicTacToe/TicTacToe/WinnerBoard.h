#pragma once
#ifndef WINNER_BOARD_h
#define WINNER_BOARD_h
#include "Entity.h"
#include "Text.h"
#include "Piece.h"
#include "TopLeftPanel.h"
namespace TicTacToe
{
	class WinnerBoard : public TopLeftPanel
	{
	public:
		WinnerBoard();
		~WinnerBoard();
		static WinnerBoard& Instance();
		void Reset() override;
		void SetWinnerPieceType(Piece::PieceType pieceType);
		void SetHeader(const std::string header);
		static const char* CURRENT_WINNER_TEXT;
		static const char* TIE_TEXT;
	private:
	};
}
#endif
