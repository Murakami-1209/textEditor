// TextEditor.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "TextEditor/EditorController/editor_controller.h"
#include "TextEditor/FileIOService/file_io_service.h"

#include <iostream>

int main(const int argc,const char* argv[])
{
	const char* file_name = nullptr;
	if (argc > 1) {
		// ファイル指定あり
		file_name = argv[1];
	}

	// ファイル読み込み
	auto io_service = FileIOService();
	std::vector<std::string> read_text;
	if (!(io_service.readTextFile(file_name, read_text))) {
		// ファイル読み込み失敗
		return -1;
	}

	// テキストエディタ初期化
	Editor::EditorController editor(read_text);

	// テキストエディタ　メインループ
	editor.main();

	return 0;
}

