#include "editor_controller.h"
#include "TextEditor/ConsoleService/console_service.h"
#include "TextEditor/Cursor/cursor.h"
#include "TextEditor/Text/text.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <wchar.h>
#include <windows.h>

namespace Editor {
	// 更新間隔（ms）
	const int UPDATE_FLAME = 16;	
	EditorController::EditorController(const std::vector<std::string>& text)
	{
		m_text = new Text(text);
		m_cursor = new Cursor();
	}
	EditorController::~EditorController()
	{
		// メンバのポインタ変数を解放
		delete m_text;
		delete m_cursor;
	}

	// エディタのメインループ処理
	int EditorController::main()
	{
		int count = 0;
		ConsoleService service = ConsoleService();
		while (true) {
			if (count % 30 == 0) {
				service.writeConsoleAll(m_text->getText());
			}
			service.writeConsole("hello");
			Sleep(UPDATE_FLAME);
			count++;
		}
		return 0;
	}
}