#pragma once
#ifndef SCORE_BOARD_h
#define SCORE_BOARD_h
#include "Entity.h"
#include "Text.h"
#include "Piece.h"
namespace TicTacToe
{
	class ScoreBoard :Commons::Entity // Keeps track of the current score. 
									 // Reseting clears the grid but does not reset the scores
	{
	public:
		ScoreBoard();
		~ScoreBoard();
		static ScoreBoard& Instance();
		void SetPosition(const Commons::Vector2D<float>& position) override;
		void Draw() override;
		void SetTexts(const std::string& font);
		void IncrementScore(const Piece::PieceType pieceType);
	private:
		static const char* SCORE_HEADER_TEXT;
		static const char* O_NAME_TEXT;
		static const char* X_NAME_TEXT;
		static const int SCORE_MIN = 0;
		static const int SCORE_MAX = 999;
		static const float SCORE_BOARD_POS_X;
		static const float SCORE_BOARD_POS_Y;
		static const float SCORE_X_OFFSET;
		static const float SCORE_Y_OFFSET;
		void SetScore(Commons::Text& scoreText, int& score);
		void IncrementScore(Commons::Text& scoreText, int& score);
		std::unique_ptr <Commons::Text> scoreHeaderText = std::make_unique<Commons::Text>();
		std::unique_ptr <Commons::Text> ONameText = std::make_unique<Commons::Text>();
		std::unique_ptr <Commons::Text> OScoreText = std::make_unique<Commons::Text>();
		int OScore = 0;
		std::unique_ptr <Commons::Text> XNameText = std::make_unique<Commons::Text>();
		std::unique_ptr <Commons::Text> XScoreText = std::make_unique<Commons::Text>();
		int XScore = 0;

	};
}
#endif

