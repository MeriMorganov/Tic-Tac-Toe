#include "Grid.h"
namespace TicTacToe
{
	const float Grid::GRID_POS_X = 350.0f;
	const float Grid::GRID_POS_Y = 50.0f;
	const float Grid::GRID_OFFSET = 100.0f;

	Grid::Grid()
	{
		pieces = std::shared_ptr<Piece[]>(new Piece[MAX_PIECES]());
		gridPosition = std::unique_ptr<Commons::Vector2D<float>>(new Commons::Vector2D<float>(GRID_POS_X, GRID_POS_Y));
	}
	Grid::~Grid()
	{

	}

	void Grid::InitializeGrid()
	{
		std::unique_ptr<Commons::Vector2D<float>> offset = std::make_unique<Commons::Vector2D<float>>();
		offset->x = 0;
		offset->y = 0;
		for (int i = 0; i < MAX_PIECES; i++)
		{
			if (i % GRID_WIDTH == 0)
			{
				offset->y++;
				offset->x = 0;
			}
			pieces[i].Reset();
			pieces[i].SetPosition(Commons::Vector2D<float>(GRID_POS_X+(GRID_OFFSET * offset->x), GRID_POS_Y+ (GRID_OFFSET * offset->y)));
			offset->x++;
		}
		SetPosition(*gridPosition);
	}
	void Grid::Reset()
	{
		InitializeGrid();
	}
	void Grid::SetPosition(const Commons::Vector2D<float>& position)
	{
		gridSprite->SetPosition(sf::Vector2f(position.x, position.y));
	}
	void Grid::Draw()
	{
		gridSprite->Draw();
		DrawPieces();
	}

	void Grid::DrawPieces()
	{
		for (int i = 0; i < MAX_PIECES; i++)
		{
			pieces[i].Draw();
		}
	}
	void Grid::CheckForPiecesMouseClick(sf::Event& event)
	{
		if (Commons::InputManager::Instance().IsLeftMouseClick(event))
		{
			for (int i = 0; i < MAX_PIECES; i++)
			{
				if (pieces[i].GetPieceType() == Piece::PieceType_None)
				{
					sf::FloatRect bounds = pieces[i].GetCurrentSprite()->GetGlobalBounds();
					if (bounds.contains(Commons::AppWindow::Instance().GetMousePos()))
					{
						pieces[i].SetPieceType(TurnManager::Instance().GetCurrentTurn());
						isGameDone = CheckIfGameDone();
						TurnManager::Instance().SetNextTurn();
					}
				}
			}
		}
	}
	bool Grid::CheckIfGameDone()
	{
		Piece::PieceType currentTurn = TurnManager::Instance().GetCurrentTurn();
		if (CheckIfTie() || 
			CheckIfHorizontalRow(currentTurn) ||
			CheckIfVerticalRow(currentTurn) ||
			CheckIfDiagonalRow(currentTurn))
		{
			std::cout << "You win!";
			return true;
		}

		return false;
	}

	bool Grid::CheckRowWin(const Piece::PieceType& pieceType, int first, int second, int third)
	{
		if (pieces[first].GetPieceType() == pieceType && 
			pieces[second].GetPieceType() == pieceType && 
			pieces[third].GetPieceType() == pieceType)
		{
			return true;
		}
		return false;
	}

	bool Grid::CheckIfTie()
	{
		for (int i = 0; i < MAX_PIECES; i++)
		{
			if (pieces[i].GetPieceType() == Piece::PieceType_None)
			{
				return false;
			}
		}
		return true;
	}
	/*
		0 1 2
		3 4 5
	    6 7 8
	*/
	bool Grid::CheckIfHorizontalRow(const Piece::PieceType& pieceType) 
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			if (CheckRowWin(pieceType, 0 + (i * GRID_WIDTH), 1 + (i * GRID_WIDTH), 2 + (i * GRID_WIDTH)))
			{
				return true;
			}
		}
		return false;
	}
	bool Grid::CheckIfVerticalRow(const Piece::PieceType& pieceType)
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			if (CheckRowWin(pieceType, 0 + i, 3 + i, 6 + i))
			{
				return true;
			}
		}
		return false;
	}
	bool Grid::CheckIfDiagonalRow(const Piece::PieceType& pieceType)
	{
		if (CheckRowWin(pieceType,0,4,8) ||
			CheckRowWin(pieceType, 2, 4, 6))
		{
			return true;
		}
		return false;
	}
	bool Grid::IsGameDone()
	{
		return isGameDone;
	}
}