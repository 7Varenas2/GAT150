#pragma once
#include "Random.h"
#include <iostream>
#include <cstdint>
#include <string>

namespace neum
{
	//typedef unsigned char u8_t; // Unsigned 8 bits type
	using u8_t = unsigned char;

	struct Color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;

		uint8_t operator [] (size_t index) const { return (&r)[index]; }
		uint8_t& operator[] (size_t index) { return (&r)[index]; }

		/* DO HOMEWORK DECLARE AS VECTOR2*/
		static const Color white;
		static const Color black;
		static const Color red;
		static const Color green;
		static const Color blue;
	

		friend std::istream& operator >> (std::istream& stream, Color& color);
	};

	std::ostream& operator << (std::ostream& stream, const Color& color);

	inline std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);
		std::string str;

		// Red 
		str = line.substr(line.find("{") + 1, line.find(",") - 1);
		color.r = (uint8_t)(std::stof(str) * 255);

		str = line.substr(line.find(",") + 1);
		color.g = (uint8_t)(std::stof(str) * 255);

		str = line.substr(line.find(",") + 1, line.find("}") - line.find(",") - 1);
		color.b = (uint8_t)(std::stof(str) * 255);
		
		//color.r = rands::random(255);
		//color.g = rands::random(255);
		//color.b = rands::random(255);

		color.a = 255;
	

		return stream;
	}

	std::ostream& operator<<(std::ostream& stream, const Color& color)
	{
		stream << (int)color.r << " " << (int)color.g << " " << (int)color.b << " " << (int)color.a;

		return stream;
	}
}

