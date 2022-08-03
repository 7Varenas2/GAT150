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

		friend std::istream& operator >> (std::istream& stream, Color& color);
	};

	inline std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);
		std::string str;

		color.r = rands::random(255);
		color.g = rands::random(255);
		color.b = rands::random(255);
		color.a = 255;
	
		return stream;
	}
}

