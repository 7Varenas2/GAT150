#pragma once
#include <string>
//void* can hold any adress of any type

namespace neum
{
	class Resource
	{
	public:
		virtual bool Create(const std::string name, ...) = 0 ;

	};
}


