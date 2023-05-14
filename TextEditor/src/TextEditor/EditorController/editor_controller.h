#pragma once

#include <string>
#include <vector>

namespace Editor {
	class Text;
	class Cursor;

	class EditorController
	{
	public:
		// コンストラクタ（指定テキストファイル読み込み）
		EditorController(const std::vector<std::string>& text);
		~EditorController();
		int main();

	private:
		Editor::Text* m_text;
		Editor::Cursor* m_cursor;
	};

}