#include "Vector3.h"

Vector3::Vector3()
	: mX(0.0f)
	, mY(0.0f)
	, mZ(0.0f)
{
}

Vector3::Vector3(const float x, const float y, const float z)
	: mX(x)
	, mY(y)
	, mZ(z)
{
}

Vector3 Vector3::GetVector() const
{
	return Vector3(mX, mY, mZ);
}

float Vector3::GetX() const
{
	return mX;
}

float Vector3::GetY() const
{
	return mY;
}

float Vector3::GetZ() const
{
	return mZ;
}

void Vector3::SetVector(const float x, const float y, const float z)
{
	mX = x;
	mY = y;
	mZ = z;
}

void Vector3::SetX(const float x)
{
	mX = x;
}

void Vector3::SetY(const float y)
{
	mY = y;
}

void Vector3::SetZ(const float z)
{
	mZ = z;
}

float Vector3::GetLength() const
{
	return std::sqrtf((mX * mX) + (mY * mY) + (mZ * mZ));
}

float Vector3::GetLengthSq() const
{
	return (mX * mX) + (mY * mY) + (mZ * mZ);
}

void Vector3::Normalize()
{
	float length = GetLength();
	mX /= length;
	mY /= length;
	mZ /= length;
}

Vector3 Vector3::Normalized() const
{
	Vector3 vector(mX, mY, mZ);
	vector.Normalize();
	return vector;
}

Vector3 Vector3::ClampLength(const Vector3& vector, float maxLength)
{
	float lengthSq = vector.GetLengthSq();
	if (lengthSq > maxLength * maxLength)
	{
		float num = std::sqrtf(lengthSq);
		float num2 = vector.mX / num;
		float num3 = vector.mY / num;
		float num4 = vector.mZ / num;
		return Vector3(num2 * maxLength, num3 * maxLength, num4 * maxLength);
	}

	return vector;
}

float Vector3::GetDistance(const Vector3& lhs, const Vector3& rhs)
{
	float xLength = rhs.mX - lhs.mX;
	float yLength = rhs.mY - lhs.mY;
	float zLength = rhs.mZ - lhs.mZ;
	return std::sqrtf((xLength * xLength) + (yLength * yLength) + (zLength * zLength));
}

float Vector3::GetDistanceSq(const Vector3& lhs, const Vector3& rhs)
{
	float xLength = rhs.mX - lhs.mX;
	float yLength = rhs.mY - lhs.mY;
	float zLength = rhs.mZ - lhs.mZ;
	return (xLength * xLength) + (yLength * yLength) + (zLength * zLength);
}

float Vector3::Dot(const Vector3& lhs, const Vector3& rhs)
{
	return (lhs.mX * rhs.mX) + (lhs.mY + rhs.mY) + (lhs.mZ + rhs.mZ);
}

Vector3 Vector3::Cross(const Vector3 lhs, const Vector3& rhs)
{
	return Vector3(
		lhs.mY * rhs.mZ - lhs.mZ * rhs.mY,
		lhs.mZ * rhs.mX - lhs.mX * rhs.mZ,
		lhs.mX * rhs.mY - lhs.mY * rhs.mX);
}

float Vector3::GetAngle(const Vector3& lhs, const Vector3& rhs)
{
	float length = std::sqrtf(lhs.GetLengthSq() * rhs.GetLengthSq());
	float dot = Dot(lhs, rhs);
	float cosAngle = std::acosf(dot / length);
	cosAngle = Rad2Deg(cosAngle);
	return (lhs.mX * rhs.mY - lhs.mY * rhs.mX > 0.0f) ? cosAngle : -cosAngle;
}

Vector3 Vector3::operator+(const Vector3& other)
{
	return Vector3(*this) += other;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	return Vector3(*this) -= other;
}

Vector3 Vector3::operator-()
{
	return Vector3(0.0f - mX, 0.0f - mY, 0.0f - mZ);
}

Vector3 Vector3::operator*(const float scalar)
{
	return Vector3(*this) *= scalar;
}

Vector3 Vector3::operator/(const float scalar)
{
	return Vector3(*this) /= scalar;
}

Vector3 Vector3::operator+=(const Vector3& other)
{
	mX += other.mX;
	mY += other.mY;
	mZ += other.mZ;
	return *this;
}

Vector3 Vector3::operator-=(const Vector3& other)
{
	mX -= other.mX;
	mY -= other.mY;
	mZ -= other.mZ;
	return *this;
}

Vector3 Vector3::operator*=(const Vector3& other)
{
	mX *= other.mX;
	mY *= other.mY;
	mZ *= other.mZ;
	return *this;
}

Vector3 Vector3::operator*=(const float scalar)
{
	mX *= scalar;
	mY *= scalar;
	mZ *= scalar;
	return *this;
}

Vector3 Vector3::operator/=(const float scalar)
{
	mX /= scalar;
	mY /= scalar;
	mZ /= scalar;
	return *this;
}

bool Vector3::operator==(const Vector3& other)
{
	float xAbs = std::abs(mX - other.mX);
	float yAbs = std::abs(mY - other.mY);
	float zAbs = std::abs(mZ - other.mZ);
	return (xAbs <= FLT_EPSILON && yAbs <= FLT_EPSILON && zAbs <= FLT_EPSILON);
}

bool Vector3::operator!=(const Vector3& other)
{
	return !(*this == other);
}