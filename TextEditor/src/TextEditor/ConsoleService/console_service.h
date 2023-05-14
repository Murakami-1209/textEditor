#pragma once

#include <string>
#include <vector>
#include <windows.h>

namespace Editor {
	class ConsoleService
	{
	public:
		ConsoleService();
		~ConsoleService();
		bool writeConsoleAll(std::vector<std::string> text);
		bool writeConsole(const std::string text);

	private:
		HANDLE getStdHandle(DWORD std_handle);
		bool initConsoleBuffer();
		COORD getConsoleTextSize();
	};
}