#pragma once

#include <cmath>

class Vector3
{
public:
	Vector3() = default;
	Vector3(float x, float y, float z);
	Vector3(const Vector3& source) = default;
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

	static float Dot(const Vector3& left, const Vector3& right);
	static Vector3 Cross(const Vector3& left, const Vector3& right);

	static float GetCosTheta(const Vector3& left, const Vector3& right);
	bool IsNormal(const Vector3& left, const Vector3& right);

	void Normalize();
	Vector3 Normalized();

	Vector3 operator+(const Vector3& source) const;
	Vector3 operator-(const Vector3& source) const;
	Vector3 operator*(const int value) const;

	Vector3 operator+=(const Vector3& source);
	Vector3 operator-=(const Vector3& source);
	Vector3 operator*=(const int value);
	bool operator==(const Vector3& source) const;

private:
	float mX;
	float mY;
	float mZ;
};

