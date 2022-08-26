#include "Model.h"
#include"../Core/File.h"
#include "../Core/Logger.h"
#include "../Math/Transform.h"
#include "../Math/MathUtils.h"

#include <iostream>
#include <sstream>

namespace neum 
{
	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_radius = CalculateRadius();

	}

	bool Model::Create(const std::string filename, ...)
	{
		if (!Load(filename))
		{
			LOG("Error");
			return false;

		}
		return true;
	}

	//bool Model::Create(const std::string& filename)
	//{
	//	if (!Load(filename))
	//	{
	//		LOG("Error could not create model %s", filename.c_str());
	//		return false;
	//	}
	//	return true;
	//}

	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, const float scale)
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
		if (m_points.size() == 0)
		{
			return;
		}

		for (auto i = 0; i < m_points.size() - 1; i++)
		{
			Vector2 p1 = mx * m_points[i];
			Vector2 p2 = mx * m_points[i  + 1];

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	bool Model::Load(const std::string& filename)
	{
		std::string buffer;
		//anvilHM::ReadFile(fileName, buffer);
		if (!neum::ReadFile(filename, buffer))
		{
			LOG("ERROR COULD NOT LOAD MODEL %s", filename.c_str());
			return false;
		}

		// read color
		std::istringstream stream(buffer);
		stream >> m_color;

		std::string line;
		std::getline(stream, line);
		//get number of points
		size_t numPoints = std::stoi(line);

		//read model points 
		for (size_t i = 0; i < numPoints; i++) //just to check
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
