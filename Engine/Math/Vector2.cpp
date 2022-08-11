#include "Vector2.h"
namespace neum 
{
	const Vector2 Vector2::one{ 1,1 };
	const Vector2 Vector2::zero{ 0,0 };
	const Vector2 Vector2::up{ 0,-1 };
	const Vector2 Vector2::down{ 0,1 };
	const Vector2 Vector2::left{ 1,0 };
	const Vector2 Vector2::right{ -1,0 };

	inline std::istream& operator >> (std::istream& stream, neum::Vector2& v)
	{
		std::string line;
		std::getline(stream, line);

		// { ##, ## }
		std::string xs = line.substr(line.find("{") + 1, line.find(",") - line.find("{") - 1);
		v.x = std::stof(xs);

		std::string ys = line.substr(line.find(",") + 1, line.find("}") - line.find(",") - 1);
		v.y = std::stof(ys);
		return stream;
	}
}