#include "WinnerBoard.h"
namespace TicTacToe
{
	const char* WinnerBoard::CURRENT_WINNER_TEXT = "Current Winner";
	const char* WinnerBoard::TIE_TEXT = "It's a tie!";

	WinnerBoard::WinnerBoard() :TopLeftPanel(CURRENT_WINNER_TEXT)
	{
		Reset();
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
}