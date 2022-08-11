#pragma once
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "MathUtils.h"
#include "Vector2.h"

namespace neum
{
	struct Transform
	{
		Vector2 position;
		float rotation { 0 };
		Vector2 scale{ 1, 1 };

		operator Matrix3x3 () const
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			return { mxScale * mxRotation * mxTranslation };
		}
	};
}
