#pragma once

#include <cmath>
#include <cfloat>

#include "Utility.h"

class Vector2
{
public:
	Vector2();
	Vector2(const float x, const float y);
	Vector2(const Vector2& ref) = default;
	~Vector2() = default;

	Vector2 GetVector() const;
	float GetX() const;
	float GetY() const;

	void SetVector(const float x, const float y);
	void SetX(const float x);
	void SetY(const float y);

	float GetLength() const;
	float GetLengthSq() const;

	void Normalize();
	Vector2 Normalized() const;

	static Vector2 ClampLength(const Vector2& vector, float maxLength);
	static float GetDistance(const Vector2& lhs, const Vector2& rhs);
	static float Dot(const Vector2& lhs, const Vector2& rhs);
	static float GetAngle(const Vector2& lhs, const Vector2& rhs);

	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator-();
	Vector2 operator/(const float scalar);
	Vector2 operator*(const float scalar);

	Vector2 operator+=(const Vector2& other);
	Vector2 operator-=(const Vector2& other);
	Vector2 operator*=(const Vector2& other);
	Vector2 operator/=(const float scalar);
	Vector2 operator*=(const float scalar);

	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);

private:
	float mX;
	float mY;
};

