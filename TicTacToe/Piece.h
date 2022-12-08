#pragma once
#ifndef PIECE_h
#define PIECE_h
#include "Entity.h"
#include "Sprite.h"
#include "AppWindow.h"
namespace TicTacToe
{
	class Piece: Commons::Entity
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
		static const sf::Uint8 NONE_TRANSPARENCY = 124;
		static const int MAX_PIECES = 3;

		static const char* PIECE_NONE_FILEPATH;
		static const char* PIECE_O_FILEPATH;
		static const char* PIECE_X_FILEPATH;

		PieceType pieceType; //Either X or O or none
		std::shared_ptr<Commons::Sprite[]> pieceSprites;

		void LoadPieceSprites();

	};
}
#endif
