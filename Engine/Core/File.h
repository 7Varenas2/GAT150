#pragma once
#include <string>

namespace neum
{
	void SetFilePath(const std::string& pathname);
	void SetFilePath(const std::string& pathname);
	std::string GetFilePath();

	bool FileExists(const std::string& pathname);
	bool GetFileSize(const std::string& pathname, size_t& size);
	bool ReadFile(const std::string& pathname, std::string& buffer);
}