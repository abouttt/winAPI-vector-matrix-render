#pragma once

#include <cmath>
#include <cfloat>

#include "Utility.h"

class Vector3
{
public:
	Vector3();
	Vector3(const float x, const float y, const float z);
	Vector3(const Vector3& ref) = default;
	~Vector3() = default;

	Vector3 GetVector() const;
	float GetX() const;
	float GetY() const;
	float GetZ() const;

	void SetVector(const float x, const float y, const float z);
	void SetX(const float x);
	void SetY(const float y);
	void SetZ(const float z);

	float GetLength() const;
	float GetLengthSq() const;

	void Normalize();
	Vector3 Normalized() const;

	static Vector3 ClampLength(const Vector3& vector, float maxLength);

	static float GetDistance(const Vector3& lhs, const Vector3& rhs);
	static float GetDistanceSq(const Vector3& lhs, const Vector3& rhs);

	static float Dot(const Vector3& lhs, const Vector3& rhs);
	static Vector3 Cross(const Vector3 lhs, const Vector3& rhs);
	static float GetAngle(const Vector3& lhs, const Vector3& rhs);

	Vector3 operator+(const Vector3& other);
	Vector3 operator-(const Vector3& other);
	Vector3 operator-();
	Vector3 operator*(const float scalar);
	Vector3 operator/(const float scalar);

	Vector3 operator+=(const Vector3& other);
	Vector3 operator-=(const Vector3& other);
	Vector3 operator*=(const Vector3& other);
	Vector3 operator*=(const float scalar);
	Vector3 operator/=(const float scalar);

	bool operator==(const Vector3& other);
	bool operator!=(const Vector3& other);

private:
	float mX;
	float mY;
	float mZ;
};

