#include "ErrorCode/result_displayer.h"

#include <iostream>

namespace Editor {
	// 結果表示用関数
	// TODO:エラーコード追加時はswitchの分岐を追加する
	void ResultDisplayer::dislplayResult(ErrorCode code)
	{
		const char* result_text;
		switch (code)
		{
		case Editor::ResultDisplayer::ErrorCode::ERROR_CODE_SUCCESS:
			result_text = "success";
			break;
		case Editor::ResultDisplayer::ErrorCode::ERROR_CODE_FAILED_READ_FILE:
			result_text = "failed to read";
			break;
		case Editor::ResultDisplayer::ErrorCode::ERROR_CODE_FAILED_OUTPUT_FILE:
			result_text = "failed to write";
			break;
		default:
			result_text = "occur something to wrong";
			break;
		}

		std::cout << result_text << std::endl;
	}
}
