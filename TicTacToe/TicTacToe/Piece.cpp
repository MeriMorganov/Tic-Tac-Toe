#include "Piece.h"
namespace TicTacToe
{
	const char* Piece::PIECE_NONE_FILEPATH = "Assets/TicTacToe_None_Piece.png";
	const char* Piece::PIECE_O_FILEPATH =	 "Assets/TicTacToe_O_Piece.png";
	const char* Piece::PIECE_X_FILEPATH =    "Assets/TicTacToe_X_Piece.png";
	const unsigned char& Piece::NONE_TRANSPARENCY = 124;

	Piece::Piece()
	{
		pieceType = PieceType::PieceType_None;
		LoadPieceSprites();
	}
	Piece::~Piece()
	{

	}
	Piece::PieceType Piece::GetPieceType()
	{
		return pieceType;
	}
	Commons::Sprite* Piece::GetCurrentSprite()
	{
		return &pieceSprites[pieceType];
	}
	void  Piece::SetPieceType(const PieceType& pieceTypeParam)
	{
		pieceType = pieceTypeParam;
	}
	void Piece::Reset()
	{
		SetPieceType(PieceType_None);
	}
	void Piece::SetPosition(const Commons::Vector2D<float>& position)
	{
		for (int i = 0; i < PieceType_Max; i++)
		{
			pieceSprites[i].SetPosition(position);
		}
	}
	void Piece::Draw()
	{
		pieceSprites[pieceType].Draw();
	}
	bool Piece::CheckForMouseClick(sf::Event& event)
	{
		sf::FloatRect bounds = GetCurrentSprite()->GetGlobalBounds();
		return bounds.contains(Commons::AppWindow::Instance().GetMousePos());
	}
	void Piece::LoadPieceSprites()
	{
		pieceSprites = std::unique_ptr<Commons::Sprite[]>(new Commons::Sprite[PieceType_Max]());
		pieceSprites[PieceType_None].SetSprite(PIECE_NONE_FILEPATH);
		pieceSprites[PieceType_None].SetTransparency(NONE_TRANSPARENCY);
		pieceSprites[PieceType_OPiece].SetSprite(PIECE_O_FILEPATH);
		pieceSprites[PieceType_XPiece].SetSprite(PIECE_X_FILEPATH);
	}

}