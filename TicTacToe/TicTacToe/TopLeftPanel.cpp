#include "TopLeftPanel.h"
namespace TicTacToe
{
	const float TopLeftPanel::TOP_LEFT_PANEL_POS_X = 20.0f;
	const float TopLeftPanel::TOP_LEFT_PANEL_POS_Y = 40.0f;
	const float TopLeftPanel::TOP_LEFT_PANEL_PIECE_OFFSET_X = 100.0f;
	const float TopLeftPanel::TOP_LEFT_PANEL_PIECE_OFFSET_Y = 50.0f;
	TopLeftPanel::TopLeftPanel()
	{
	}
	TopLeftPanel::TopLeftPanel(const std::string& headerText)
	{
		Reset();
		this->headerText->SetFont(TicTacToe::DEFAULT_FONT_PATH);
		this->headerText->SetText(headerText);
		SetPosition(Commons::Vector2D<float>(TOP_LEFT_PANEL_POS_X, TOP_LEFT_PANEL_POS_Y));
	}
	TopLeftPanel::~TopLeftPanel()
	{

	}
	void TopLeftPanel::SetPosition(const Commons::Vector2D<float>& position)
	{
		headerText->SetPosition(position);
		piece->SetPosition(Commons::Vector2D<float>(position.x + TOP_LEFT_PANEL_PIECE_OFFSET_X, position.y + TOP_LEFT_PANEL_PIECE_OFFSET_Y));
	}
	void TopLeftPanel::Draw()
	{
		piece->Draw();
		headerText->Draw();
	}
}