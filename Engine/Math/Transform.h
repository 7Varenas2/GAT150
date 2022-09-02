#pragma once
#include "Vector2.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "MathUtils.h"
#include "Serialization/Serializable.h"

namespace neum
{
	struct Transform : public ISerializable
	{
		Vector2 position;
		float rotation;
		Vector2 scale{ 1, 1 };

		Matrix3x3 matrix;
		
		Transform(const Vector2& position, float rotation, const Vector2& scale) :
			position{ position },
			rotation{ rotation },
			scale{ scale }
		{}
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;


		
		void Update()
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			matrix = { mxTranslation * mxRotation * mxScale };
		}

		void Update(const Matrix3x3& parent)
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			matrix = { mxTranslation * mxRotation * mxScale };
			matrix = parent * matrix;

		}

		operator Matrix2x2 () const
		{
			Matrix2x2 mxS = Matrix2x2::CreateScale(scale);
			Matrix2x2 mxR = Matrix2x2::CreateRotation(math::DegToRad(rotation));

			return { mxS * mxR };
		}

		operator Matrix3x3 () const
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			return { mxScale * mxRotation * mxTranslation };
		}


		//virtual bool Write(const rapidjson::Value& value) const override;
		//virtual bool Read(const rapidjson::Value& value) override;
	};
}
