#include "TurnManager.h"
namespace TicTacToe
{
	const float TurnManager::CURRENT_TURN_POS_X = 20.0f;
	const float TurnManager::CURRENT_TURN_POS_Y = 40.0f;
	const float TurnManager::CURRENT_TURN_PIECE_OFFSET_X = 100.0f;
	const float TurnManager::CURRENT_TURN_PIECE_OFFSET_Y = 50.0f;
	const char* TurnManager::CURRENT_TURN_TEXT = "Current Turn";
	TurnManager::TurnManager()
	{
		Reset();
		text->SetFont(TicTacToe::DEFAULT_FONT_PATH);
		text->SetText(CURRENT_TURN_TEXT);
		SetPosition(Commons::Vector2D<float>(CURRENT_TURN_POS_X, CURRENT_TURN_POS_Y));
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
		currentTurnPiece->SetPieceType(Piece::PieceType_XPiece);
	}

	void TurnManager::SetPosition(const Commons::Vector2D<float>& position)
	{
		text->SetPosition(sf::Vector2f(position.x, position.y));
		currentTurnPiece->SetPosition(Commons::Vector2D<float>(position.x + CURRENT_TURN_PIECE_OFFSET_X, 
			position.y + CURRENT_TURN_PIECE_OFFSET_Y));
	}

	void TurnManager::Draw()
	{
		currentTurnPiece->Draw();
		text->Draw();
	}

	Piece::PieceType TurnManager::GetCurrentTurn()
	{
		return currentTurnPiece->GetPieceType();
	}

	void TurnManager::SetNextTurn()
	{
		currentTurnPiece->GetPieceType() == Piece::PieceType_OPiece ? 
			currentTurnPiece->SetPieceType(Piece::PieceType_XPiece) : 
			currentTurnPiece->SetPieceType(Piece::PieceType_OPiece);
	}
	void TurnManager::SetNoTurn()
	{
		currentTurnPiece->SetPieceType(Piece::PieceType_None);
	}
}