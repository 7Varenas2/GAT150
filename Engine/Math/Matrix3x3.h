#pragma once
#include "Vector2.h"
#include "Vector3.h"

namespace neum
{
	struct Matrix3x3
	{
	public:

		Vector3 rows[3]; //[3][3][3]

		Matrix3x3() = default;
		Matrix3x3(const Vector3& row1, const Vector3& row2, const Vector3& row3);

		Vector3 operator [] (size_t index) const { return rows[index]; }
		Vector3& operator [] (size_t index) { return rows[index]; }

		Vector2 operator * (const Vector2& v) const;
		Matrix3x3 operator * (const Matrix3x3& mx) const;

		Vector2 GetTranslation() const;
		float GetRotation() const;
		Vector2 GetScale() const;

		static Matrix3x3 CreateScale(const Vector2& scale);
		static Matrix3x3 CreateScale(float scale);
		static Matrix3x3 CreateRotation(float radians);
		static Matrix3x3 CreateTranslation(const Vector2& translate);

		static const Matrix3x3 identity;
		static const Matrix3x3 zero;

	};

	inline Matrix3x3::Matrix3x3(const Vector3& row1, const Vector3& row2, const Vector3& row3)
	{
		rows[0] = row1;
		rows[1] = row2;
		rows[2] = row3;

	}

	inline Vector2 Matrix3x3::operator*(const Vector2& v) const
	{
		return Vector2();
	}

	inline Matrix3x3 Matrix3x3::operator*(const Matrix3x3& mx) const
	{
		return Matrix3x3();
	}

	inline Vector2 Matrix3x3::GetTranslation() const
	{

		return { rows[0][2], rows[1][2] };
	}
	inline float Matrix3x3::GetRotation() const
	{

		return std::atan2(rows[1][0], rows[0][0]);
	}
	inline Vector2 Matrix3x3::GetScale() const
	{
		Vector2 x = { rows[0][0], rows[0][1] };
		Vector2 y = { rows[1][0], rows[1][1] };

		return { x.Length(), y.Length() };
	}

	inline Matrix3x3 Matrix3x3::CreateScale(const Vector2& scale)
	{

		Matrix3x3 mx = identity;

		mx[0][0] = scale.x;
		mx[1][1] = scale.y;

		return mx;
	}

	inline Matrix3x3 Matrix3x3::CreateScale(float scale)
	{

		Matrix3x3 mx = identity;

		mx[0][0] = scale;
		mx[1][1] = scale;

		return mx;
	}

	inline Matrix3x3 Matrix3x3::CreateRotation(float radians)
	{
		Matrix3x3 mx;

		float c = std::cos(radians);
		float s = std::sin(radians);

		mx[0] = { c , -s, 0.0f };
		mx[1] = { s , c , 0.0f };
		mx[2] = { 0.0f , 0.0f , 1.0f };

		return mx;
	}

	inline Matrix3x3 Matrix3x3::CreateTranslation(const Vector2& translate)
	{
		Matrix3x3 mx = identity;

		mx[0][2] = translate.x;
		mx[1][2] = translate.y;

		return mx;
	}

}
