#pragma once
#ifndef DEBUG_MSG_h
#define DEBUG_MSG_h
#include <iostream>
#include <windows.h> 
namespace Commons
{
	class DebugMsg // Print messages to the console when in debug mode
	{
	public:
		static void LogMsg(std::string msg);
		static void LogWarningMsg(std::string msg);
		static void LogErrorMsg(std::string msg);
	private:
		static const int WHITE_COLOR = 7;
		static const int RED_COLOR = 12;
		static const int YELLOW_COLOR = 14;
		static const HANDLE H_CONSOLE;
	};
}
#endif