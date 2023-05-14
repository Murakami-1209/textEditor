#pragma once

#include "Singlton/singlton.h"

namespace Editor {
	class ResultDisplayer
	{
		enum class ErrorCode {
			ERROR_CODE_SUCCESS = 0,	//成功
			ERROR_CODE_FAILED_READ_FILE = 1000,	//ファイル読み込み失敗
			ERROR_CODE_FAILED_OUTPUT_FILE = 1001,	//ファイル書き込み失敗
		};
	public:
		ResultDisplayer();
		~ResultDisplayer();
		void dislplayResult(ErrorCode code);
	};
}