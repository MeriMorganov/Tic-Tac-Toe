#include "RestartButton.h"
namespace TicTacToe
{
	const char* RestartButton::BUTTON_DEFAULT_FILEPATH = "Assets/TicTacToe_Button_Default.png";
	const char* RestartButton::BUTTON_HOVER_FILEPATH = "Assets/TicTacToe_Button_Hover.png";
	const char* RestartButton::BUTTON_CLICKED_FILEPATH = "Assets/TicTacToe_Button_Clicked.png";
	const char* RestartButton::RESTART_TEXT = "Restart";
	const float RestartButton::BUTTON_X_POS = 80.0f;
	const float RestartButton::BUTTON_Y_POS = 450.0f;

	RestartButton::RestartButton() :Button()
	{
		SetSprite(ButtonState_Default, BUTTON_DEFAULT_FILEPATH);
		SetSprite(ButtonState_Hover, BUTTON_HOVER_FILEPATH);
		SetSprite(ButtonState_Clicked, BUTTON_CLICKED_FILEPATH);
		SetText(RESTART_TEXT,TicTacToe::DEFAULT_FONT_PATH);
		SetLeftTextPadding(7.0f);
		SetTopTextPadding(4.0f);
		SetPosition(sf::Vector2f(BUTTON_X_POS, BUTTON_Y_POS));
	}

	RestartButton::~RestartButton()
	{
	}
}
