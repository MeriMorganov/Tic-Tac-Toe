#pragma once
#ifndef RESTART_BUTTON_h
#define RESTART_BUTTON_h
#include "Globals.h"
#include "Button.h"
namespace TicTacToe
{
	class RestartButton : public Commons::Button
	{
	public:
		static const char* BUTTON_DEFAULT_FILEPATH;
		static const char* BUTTON_HOVER_FILEPATH;
		static const char* BUTTON_CLICKED_FILEPATH;
		static const char* RESTART_TEXT;
		static const float BUTTON_X_POS;
		static const float BUTTON_Y_POS;
		RestartButton();
		~RestartButton();
	};
}
#endif
