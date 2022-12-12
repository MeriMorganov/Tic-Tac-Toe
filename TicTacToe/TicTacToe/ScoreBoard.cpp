#include "ScoreBoard.h"
namespace TicTacToe
{
	const char* ScoreBoard::SCORE_HEADER_TEXT = "Score";
	const char* ScoreBoard::O_NAME_TEXT = "O:";
	const char* ScoreBoard::X_NAME_TEXT = "X:";
	const float ScoreBoard::SCORE_BOARD_POS_X = 750.0f;
	const float ScoreBoard::SCORE_BOARD_POS_Y = 40.0f;
	const float ScoreBoard::SCORE_X_OFFSET = 40.0f;
	const float ScoreBoard::SCORE_Y_OFFSET = 40.0f;
	ScoreBoard::ScoreBoard()
	{
		SetTexts(TicTacToe::DEFAULT_FONT_PATH);
		SetPosition(Commons::Vector2D<float>(SCORE_BOARD_POS_X, SCORE_BOARD_POS_Y));
	}
	ScoreBoard::~ScoreBoard()
	{
	}
	ScoreBoard& ScoreBoard::Instance()
	{
		static ScoreBoard INSTANCE;
		return INSTANCE;
	}
	void ScoreBoard::SetPosition(const Commons::Vector2D<float>& position)
	{
		scoreHeaderText->SetPosition(position);
		XNameText->SetPosition(Commons::Vector2D<float>(position.x,position.y + SCORE_Y_OFFSET));
		XScoreText->SetPosition(Commons::Vector2D<float>(position.x + SCORE_X_OFFSET, position.y + SCORE_Y_OFFSET));
		ONameText->SetPosition(Commons::Vector2D<float>(position.x, position.y + (SCORE_Y_OFFSET*2)));
		OScoreText->SetPosition(Commons::Vector2D<float>(position.x + SCORE_X_OFFSET, position.y + (SCORE_Y_OFFSET*2)));


	}
	void ScoreBoard::Draw()
	{
		scoreHeaderText->Draw();
		XNameText->Draw();
		XScoreText->Draw();
		ONameText->Draw();
		OScoreText->Draw();
	}
	void ScoreBoard::SetTexts(const std::string& font)
	{
		scoreHeaderText->SetFont(font);
		scoreHeaderText->SetText(SCORE_HEADER_TEXT);
		XNameText->SetFont(font);
		XNameText->SetText(X_NAME_TEXT);
		ONameText->SetFont(font);
		ONameText->SetText(O_NAME_TEXT);

		XScore = SCORE_MIN;
		XScoreText->SetFont(font);
		SetScore(*XScoreText, XScore);

		OScore = SCORE_MIN;
		OScoreText->SetFont(font);
		SetScore(*OScoreText, OScore);
	}
	void ScoreBoard::SetScore(Commons::Text& scoreText, int& score)
	{
		scoreText.SetText(std::to_string(score));
	}
	void ScoreBoard::IncrementScore(const Piece::PieceType pieceType)
	{
		switch (pieceType)
		{
		case Piece::PieceType_OPiece:
			IncrementScore(*OScoreText, OScore);
			break;
		case Piece::PieceType_XPiece:
			IncrementScore(*XScoreText, XScore);
			break;
		}
	}
	void ScoreBoard::IncrementScore(Commons::Text& scoreText, int& score)
	{
		if (score < SCORE_MAX)
		{
			score++;
			SetScore(scoreText, score);
		}
	}
}