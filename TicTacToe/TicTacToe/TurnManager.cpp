#include "TurnManager.h"
namespace TicTacToe
{
	const char* TurnManager::CURRENT_TURN_TEXT = "Current Turn";
	TurnManager::TurnManager() :TopLeftPanel(CURRENT_TURN_TEXT)
	{
		Reset();

	}
	TurnManager::~TurnManager()
	{
	}
	TurnManager& TurnManager::Instance()
	{
		static TurnManager INSTANCE;
		return INSTANCE;
	}

	void TurnManager::Reset()
	{
		piece->SetPieceType(Piece::PieceType_XPiece);
	}

	Piece::PieceType TurnManager::GetCurrentTurn()
	{
		return piece->GetPieceType();
	}

	void TurnManager::SetNextTurn()
	{
		piece->GetPieceType() == Piece::PieceType_OPiece ?
			piece->SetPieceType(Piece::PieceType_XPiece) :
			piece->SetPieceType(Piece::PieceType_OPiece);
	}
	void TurnManager::SetNoTurn()
	{
		piece->SetPieceType(Piece::PieceType_None);
	}
}