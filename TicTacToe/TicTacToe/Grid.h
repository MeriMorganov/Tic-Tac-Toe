#pragma once
#ifndef GRID_h
#define GRID_h
#include "Entity.h"
#include "Piece.h"
#include "Sprite.h"
#include "TurnManager.h"
#include "InputManager.h"
#include "Vector2D.h"
namespace TicTacToe
{
	class Grid: Commons::Entity // The gameboard that the game is played on and contains the pieces
	{
	public:
		Grid();
		~Grid();
		void InitializeGrid();
		void Reset() override;
		void SetPosition(const Commons::Vector2D<float>& position) override;
		void Draw() override;
		void CheckForPiecesMouseClick(sf::Event& event);

		bool CheckIfGameDone();
		bool CheckIfTie();
		bool CheckIfHorizontalRow(const Piece::PieceType& pieceType);
		bool CheckIfVerticalRow(const Piece::PieceType& pieceType);
		bool CheckIfDiagonalRow(const Piece::PieceType& pieceType);
		bool IsGameDone();
	private:
		static const int GRID_WIDTH = 3;
		static const int GRID_HEIGHT = 3;
		static const int MAX_PIECES = GRID_WIDTH * GRID_HEIGHT;

		static const float GRID_POS_X;
		static const float GRID_POS_Y;
		static const float GRID_OFFSET;

		std::shared_ptr <Commons::Sprite> gridSprite = std::make_shared<Commons::Sprite>();
		std::shared_ptr <Piece[]> pieces;
		std::unique_ptr <Commons::Vector2D<float>> gridPosition;
		bool isGameDone = false;

		void DrawPieces();
		bool CheckRowWin(const Piece::PieceType& pieceType, int first, int second, int third);
	};
}
#endif
