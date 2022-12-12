#include "DebugMsg.h"
namespace Commons
{
	const HANDLE DebugMsg::H_CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);

	void DebugMsg::LogMsg(std::string msg)
	{
#ifdef _DEBUG  
		std::cout << msg << std::endl;
		SetConsoleTextAttribute(H_CONSOLE, WHITE_COLOR);
#endif
	}

	void DebugMsg::LogWarningMsg(std::string msg)
	{
#ifdef _DEBUG  
		SetConsoleTextAttribute(H_CONSOLE, YELLOW_COLOR);
		LogMsg("[WARNING] " + msg);
#endif
	}

	void DebugMsg::LogErrorMsg(std::string msg)
	{
#ifdef _DEBUG 
		SetConsoleTextAttribute(H_CONSOLE, RED_COLOR);
		LogMsg("[ERROR] " + msg);
#endif
	}
}
