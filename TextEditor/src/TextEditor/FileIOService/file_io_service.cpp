#include "TextEditor/FileIOService/file_io_service.h"

#include <fstream>
#include <iostream>

FileIOService::FileIOService()
{
	
}

FileIOService::~FileIOService()
{
}

bool FileIOService::readTextFile(const char * file_name, std::vector<std::string>& text)
{
	if (file_name == nullptr) {
		// ファイル指定がない場合終了
		return false;
	}

	std::ifstream ifs(file_name);
	if (ifs.fail()) {
		// ファイル読み込み失敗
		std::cout << "failed" << std::endl;
		return false;
	}

	std::string tmp_string;
	while (std::getline(ifs, tmp_string)) {
		// 読み込んだテキストを格納
		std::cout << tmp_string << std::endl;
		text.push_back(tmp_string);
	}
	return true;
}

bool FileIOService::outpuitTextFile(const char* file_name, const std::vector<std::string>& text)
{
	if (file_name == nullptr) {
		// ファイル名が未指定
		return false;
	}

	std::ofstream ofs(file_name);
	if (ofs.fail()) {
		// ファイル書き込み失敗
		return false;
	}

	size_t row_size = text.size();
	for (size_t i = 0; i < row_size; i++) {
		// textをファイルに書き出し
		ofs << text[i];

		if (i != (row_size - 1)) {
			// 最終行の場合は改行なし
			ofs << std::endl;
		}
	}

	return true;
}
