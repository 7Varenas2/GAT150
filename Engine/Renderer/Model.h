#pragma once
#include "Renderer.h"
#include <vector>
#include <string>
#include "../Math/Color.h"

#include "Text.h"
namespace neum 
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<Vector2>& points,  const Color& color) :
			m_points{points},
			m_color{color} {}

		Model(const std::string& filename);

		void Draw(Renderer& renderer, const Vector2 position, float angle, const Vector2& scale = Vector2{1,1});
		void Load(const std::string& filename);
		float CalculateRadius();
		float GetRadius() { return m_radius; }

	private:
		Color m_color{ 0, 0, 0, 0 };
		std::vector<Vector2> m_points;

		float m_radius = 0;
	};
}
