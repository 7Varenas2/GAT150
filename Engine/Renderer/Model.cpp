#include "Model.h"
#include"../Core/File.h"
#include "../Core/Logger.h"
#include "../Math/Transform.h"
#include "../Math/MathUtils.h"

#include <iostream>
#include <sstream>

namespace neum {
	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_radius = CalculateRadius();

	}

	bool Model::Create(const std::string& filename, void* data)
	{
		if (!Load(filename))
		{
			LOG("Error could not create model %s", filename.c_str());
			return false;
		}
		return true;
	}

	void Model::Draw(neum::Renderer& renderer, Vector2 position, float angle, const Vector2& scale)
	{
		
		// Draw Model
		for (auto i = 0; i < m_points.size() - 1; i++)
		{
			Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			Vector2 p2 = Vector2::Rotate((m_points[i + 1] * scale),angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	
	void Model::Draw(Renderer& renderer, const Transform& transform)
	{
		Matrix3x3 mx = transform.matrix;

		for (auto i = 0; i < m_points.size() - 1; i++)
		{
			Vector2 p1 = mx * m_points[i];
			Vector2 p2 = mx * m_points[i  + 1];

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	bool Model::Load(const std::string& filename) //bool
	{
		std::string buffer;
		if (!neum::ReadFile(filename, buffer))
		{
			LOG("Error could not read file %s", filename.c_str());
			return false;
		}

		
		neum::ReadFile(filename,buffer);

		// Read Color
		std::stringstream stream(buffer);
		stream >> m_color;

		// Read number of points
		std::string line;
		std::getline(stream, line);
		size_t numPoints = std::stoi(line);

		// Read model points
		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;
			m_points.push_back(point);
		}
		return true;
	}

	float Model::CalculateRadius()
	{
		float radius = 0;
		
		// Find the largest length (radius)
		for (auto& point : m_points)
		{
			if (point.Length() > radius) radius = point.Length();

		}

		return radius;
	}
}
