#include "Vector2.h"

Vector2::Vector2()
	: mX(0.0f)
	, mY(0.0f)
{
}

Vector2::Vector2(const float x, const float y)
	: mX(x)
	, mY(y)
{
}

Vector2 Vector2::GetVector() const
{
	return Vector2(mX, mY);
}

float Vector2::GetX() const
{
	return mX;
}

float Vector2::GetY() const
{
	return mY;
}

void Vector2::SetVector(const float x, const float y)
{
	mX = x;
	mY = y;
}

void Vector2::SetX(const float x)
{
	mX = x;
}

void Vector2::SetY(const float y)
{
	mY = y;
}

float Vector2::GetLength() const
{
	return std::sqrtf((mX * mX) + (mY * mY));
}

float Vector2::GetLengthSq() const
{
	return (mX * mX) + (mY * mY);
}

void Vector2::Normalize()
{
	float length = GetLength();
	mX /= length;
	mY /= length;
}

Vector2 Vector2::Normalized() const
{
	Vector2 vector(mX, mY);
	vector.Normalize();
	return vector;
}

Vector2 Vector2::ClampLength(const Vector2& vector, float maxLength)
{
	float lengthSq = vector.GetLengthSq();
	if (lengthSq > maxLength * maxLength)
	{
		float num = std::sqrtf(lengthSq);
		float num2 = vector.mX / num;
		float num3 = vector.mY / num;
		return Vector2(num2 * maxLength, num3 * maxLength);
	}

	return vector;
}

float Vector2::GetDistance(const Vector2& lhs, const Vector2& rhs)
{
	float xLength = rhs.mX - lhs.mX;
	float yLength = rhs.mY - lhs.mY;
	return std::sqrtf((xLength * xLength) + (yLength * yLength));
}

float Vector2::Dot(const Vector2& lhs, const Vector2& rhs)
{
	return (lhs.mX * rhs.mX) + (lhs.mY + rhs.mY);
}

float Vector2::GetAngle(const Vector2& lhs, const Vector2& rhs)
{
	float length = std::sqrtf(lhs.GetLengthSq() * rhs.GetLengthSq());
	float dot = Dot(lhs, rhs);
	float cosAngle = std::acosf(dot / length);
	cosAngle = Rad2Deg(cosAngle);
	return (lhs.mX * rhs.mY - lhs.mY * rhs.mX > 0.0f) ? cosAngle : -cosAngle;
}

Vector2 Vector2::operator+(const Vector2& other)
{
	return Vector2(*this) += other;
}

Vector2 Vector2::operator-(const Vector2& other)
{
	return Vector2(*this) -= other;
}

Vector2 Vector2::operator-()
{
	return Vector2(0.0f - mX, 0.0f - mY);
}

Vector2 Vector2::operator/(const float scalar)
{
	return Vector2(*this) /= scalar;
}

Vector2 Vector2::operator*(const float scalar)
{
	return Vector2(*this) *= scalar;
}

Vector2 Vector2::operator+=(const Vector2& other)
{
	mX += other.mX;
	mY += other.mY;
	return *this;
}

Vector2 Vector2::operator-=(const Vector2& other)
{
	mX -= other.mX;
	mY -= other.mY;
	return *this;
}

Vector2 Vector2::operator*=(const Vector2& other)
{
	mX *= other.mX;
	mY *= other.mY;
	return *this;
}

Vector2 Vector2::operator/=(const float scalar)
{
	mX /= scalar;
	mY /= scalar;
	return *this;
}

Vector2 Vector2::operator*=(const float scalar)
{
	mX *= scalar;
	mY *= scalar;
	return *this;
}

bool Vector2::operator==(const Vector2& other)
{
	float xAbs = std::fabsf(mX - other.mX);
	float yAbs = std::fabsf(mY - other.mY);
	return (xAbs <= FLT_EPSILON && yAbs <= FLT_EPSILON);
}

bool Vector2::operator!=(const Vector2& other)
{
	return !(*this == other);
}
