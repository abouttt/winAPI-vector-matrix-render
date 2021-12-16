#pragma once

#include <cmath>

class Vector2
{
public:
	Vector2() = default;
	Vector2(float x, float y);
	Vector2(const Vector2& source) = default;
	~Vector2() = default;

	Vector2 Get() const;
	float GetX() const;
	float GetY() const;

	void Set(const float x, const float y);
	void SetX(const float x);
	void SetY(const float y);

	float GetLength() const;
	float GetLengthSq() const;

	static float Dot(const Vector2& left, const Vector2& right);

	void Normalize();
	Vector2 Normalized();

	Vector2 operator+(const Vector2& source) const;
	Vector2 operator-(const Vector2& source) const;
	Vector2 operator*(const int value) const;

	Vector2 operator+=(const Vector2& source);
	Vector2 operator-=(const Vector2& source);
	Vector2 operator*=(const int value);
	bool operator==(const Vector2& source) const;

private:
	float mX;
	float mY;
};

