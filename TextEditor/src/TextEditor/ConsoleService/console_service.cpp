#include "TextEditor/ConsoleService/console_service.h"

#include <memory>
namespace Editor {

	ConsoleService::ConsoleService()
	{
	}

	ConsoleService::~ConsoleService()
	{
	}
	HANDLE ConsoleService::getStdHandle(DWORD std_handle)
	{
		return GetStdHandle(std_handle);
	}
	bool ConsoleService::initConsoleBuffer()
	{
		HANDLE output_handle = getStdHandle(STD_OUTPUT_HANDLE);
		COORD text_size = getConsoleTextSize();

		// 初期化用文字列作成
		std::unique_ptr<char> write_text(new char[text_size.X]);
		for (auto i = 0; i < text_size.X; i++) {
			write_text.get()[i] = ' ';
		}

		COORD new_pos = { 0,0 };
		LPDWORD num = nullptr;
		INT16 row_size = text_size.Y;
		for (INT16 i = 0; i < row_size; i++) {
			new_pos = { 0,i };
			SetConsoleCursorPosition(output_handle, new_pos);
			WriteConsoleA(output_handle, write_text.get(), text_size.X, num,NULL);
		}

		// 初期化後はカーソル位置は左上（0,0）にする
		new_pos = { 0,0 };
		SetConsoleCursorPosition(output_handle, new_pos);
		return true;
	}
	COORD ConsoleService::getConsoleTextSize()
	{
		HANDLE output_handle = getStdHandle(STD_OUTPUT_HANDLE);
		PCONSOLE_SCREEN_BUFFER_INFO buffer_info = new CONSOLE_SCREEN_BUFFER_INFO();
		GetConsoleScreenBufferInfo(output_handle, buffer_info);
		return buffer_info->dwSize;
	}
	bool ConsoleService::writeConsoleAll(std::vector<std::string> text)
	{
		initConsoleBuffer();
		return true;
	}
	bool ConsoleService::writeConsole(const std::string text)
	{
		HANDLE output_handle = getStdHandle(STD_OUTPUT_HANDLE);
		WriteConsoleA(output_handle, text.c_str(), text.size(), nullptr, NULL);
		return true;
	}
}