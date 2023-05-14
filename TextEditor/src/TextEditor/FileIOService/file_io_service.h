#pragma once
#include "Singlton/singlton.h"

#include <string>
#include <vector>

class FileIOService
{
public:
	FileIOService();
	~FileIOService();
	bool readTextFile(const char* file_name, std::vector<std::string>& text);
	bool outpuitTextFile(const char* file_name,const std::vector<std::string>& text);
};


