#pragma once
#include "Json.h"

namespace neum
{
	class ISerializable
	{
	public:
		~ISerializable() {};

		virtual bool Write(const rapidjson::Value& value) const = 0;
		virtual bool Read(const rapidjson::Value& value) = 0;
	};
}
