#pragma once
#ifndef PIECE_h
#define PIECE_h
#include "Globals.h"
#include "Entity.h"
#include "Sprite.h"
#include "AppWindow.h"
namespace TicTacToe
{
	class Piece: Commons::Entity // Piece object representing either the X or O
	{
	public:
		enum PieceType
		{
			PieceType_None = 0,
			PieceType_OPiece = 1,
			PieceType_XPiece = 2,
			PieceType_Max
		};
		
		Piece();
		~Piece();
		PieceType GetPieceType();
		Commons::Sprite* GetCurrentSprite();
		void SetPieceType(const PieceType& pieceTypeParam);
		void Reset() override;
		void SetPosition(const Commons::Vector2D<float>& position) override;
		void Draw() override;
		bool CheckForMouseClick(sf::Event& event);

	private:
		static const unsigned char& NONE_TRANSPARENCY;
		static const char* PIECE_NONE_FILEPATH;
		static const char* PIECE_O_FILEPATH;
		static const char* PIECE_X_FILEPATH;

		PieceType pieceType; //Either X or O or none
		std::unique_ptr<Commons::Sprite[]> pieceSprites;

		void LoadPieceSprites();

	};
}
#endif
