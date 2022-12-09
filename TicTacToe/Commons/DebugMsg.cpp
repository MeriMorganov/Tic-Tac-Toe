#include "DebugMsg.h"
namespace Commons
{
	const HANDLE DebugMsg::H_CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);

	void DebugMsg::LogMsg(std::string msg)
	{
		std::cout << msg << std::endl;
		SetConsoleTextAttribute(H_CONSOLE, WHITE_COLOR);
	}

	void DebugMsg::LogWarningMsg(std::string msg)
	{
		SetConsoleTextAttribute(H_CONSOLE, YELLOW_COLOR);
		LogMsg("[WARNING] " + msg);
	}

	void DebugMsg::LogErrorMsg(std::string msg)
	{
		SetConsoleTextAttribute(H_CONSOLE, RED_COLOR);
		LogMsg("[ERROR] " + msg);
	}
}
