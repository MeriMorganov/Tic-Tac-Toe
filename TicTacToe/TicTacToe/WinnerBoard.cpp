#include "WinnerBoard.h"
namespace TicTacToe
{
	const char* WinnerBoard::WINNER_MEDAL = "Assets/TicTacToe_Winner_Medal.png";
	const char* WinnerBoard::CURRENT_WINNER_TEXT = "Current Winner";
	const char* WinnerBoard::TIE_TEXT = "It's a tie!";
	const float WinnerBoard::WINNER_MEDAL_POS_X = 155.0f;
	const float WinnerBoard::WINNER_MEDAL_POS_Y = 110.0f;

	WinnerBoard::WinnerBoard() :TopLeftPanel(CURRENT_WINNER_TEXT)
	{
		Reset();
		SetWinnerMedalSprite();
	}
	WinnerBoard::~WinnerBoard()
	{
	}
	WinnerBoard& WinnerBoard::Instance()
	{
		static WinnerBoard INSTANCE;
		return INSTANCE;
	}
	void WinnerBoard::Reset()
	{
		piece->SetPieceType(Piece::PieceType_None);
	}
	void WinnerBoard::SetWinnerPieceType(Piece::PieceType pieceType)
	{
		piece->SetPieceType(pieceType);
	}
	void WinnerBoard::SetHeader(const std::string header)
	{
		headerText->SetText(header);
	}
	void WinnerBoard::DrawWinnerMedal()
	{
		winnerMedalSprite->Draw();
	}
	void WinnerBoard::SetWinnerMedalSprite()
	{
		winnerMedalSprite->SetSprite(WINNER_MEDAL);
		winnerMedalSprite->SetPosition(Commons::Vector2D<float>(WINNER_MEDAL_POS_X, WINNER_MEDAL_POS_Y));
	}
}