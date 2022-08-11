#pragma once
#include "Renderer.h"
#include "../Math/Color.h"
#include "Text.h"
#include <vector>
#include <string>

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

		bool Create(const std::string& filename);

		void Draw(Renderer& renderer, const Vector2 position, float angle, const Vector2& scale = Vector2{1,1});
		void Draw(Renderer& renderer, const Transform& transform);

		bool Load(const std::string& filename);


		float CalculateRadius();
		float GetRadius() { return m_radius; }

	private:
		Color m_color{ 0, 0, 0, 0 };
		std::vector<Vector2> m_points;
		float m_radius = 0;
	};
}
