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
		void DrawWinnerMedal();
		static const char* WINNER_MEDAL;
		static const char* CURRENT_WINNER_TEXT;
		static const char* TIE_TEXT;
		static const float WINNER_MEDAL_POS_X;
		static const float WINNER_MEDAL_POS_Y;
	private:
		void SetWinnerMedalSprite();
		std::unique_ptr <Commons::Sprite> winnerMedalSprite = std::make_unique<Commons::Sprite>();
	};
}
#endif
