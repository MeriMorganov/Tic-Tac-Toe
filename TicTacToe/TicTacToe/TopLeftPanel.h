#pragma once
#ifndef TOP_LEFT_PANEL_h
#define TOP_LEFT_PANEL_h
#include "Entity.h"
#include "Text.h"
#include "Piece.h"
namespace TicTacToe
{
	class TopLeftPanel : public Commons::Entity // Remove boiler plate code. Use this to show top left information of the scren
	{
	public:
		TopLeftPanel();
		TopLeftPanel(const std::string& headerText);
		~TopLeftPanel();
		void SetPosition(const Commons::Vector2D<float>& position) override;
		void Draw() override;
	protected:
		static const float TOP_LEFT_PANEL_POS_X;
		static const float TOP_LEFT_PANEL_POS_Y;
		static const float TOP_LEFT_PANEL_PIECE_OFFSET_X;
		static const float TOP_LEFT_PANEL_PIECE_OFFSET_Y;
		std::unique_ptr <Commons::Text> headerText = std::make_unique<Commons::Text>();
		std::unique_ptr <Piece> piece = std::make_unique<Piece>();
	};
}
#endif
