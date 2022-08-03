#include "Logger.h"

#include <cstdarg>
#include <iostream>

namespace neum
{
	Logger g_logger;
	void neum::Logger::Log(const char* format, ...)
	{
		va_list args;
		va_start(args, format);

		char str[1024]; // Declaring 1024 memory on the heap
		vsprintf_s(str, 1024, format, args);

		std::cout << str << std::endl;

		va_end(args);

	}

}
