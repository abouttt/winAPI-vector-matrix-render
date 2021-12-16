#include "Vector3.h"

Vector3::Vector3(float x, float y, float z)
	: mX(x)
	, mY(y)
	, mZ(z)
{
}

Vector3 Vector3::GetVector() const
{
	return Vector3(*this);
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

float Vector3::Dot(const Vector3& left, const Vector3& right)
{
	return (left.mX * right.mX) + (left.mY * right.mY) + (left.mZ * right.mZ);
}

Vector3 Vector3::Cross(const Vector3& left, const Vector3& right)
{
	return Vector3(
		(left.mY * right.mZ) - (left.mZ * right.mY),
		(left.mZ * right.mX) - (left.mX * right.mZ),
		(left.mX * right.mY) - (left.mY * right.mX));
}

float Vector3::GetCosTheta(const Vector3& left, const Vector3& right)
{
	return (Vector3::Dot(left, right) / (left.GetLength() * right.GetLength()));
}

bool Vector3::IsNormal(const Vector3& left, const Vector3& right)
{
	if (!Vector3::GetCosTheta(left, right))
		return true;
	else
		return false;
}

void Vector3::Normalize()
{
	mX /= GetLength();
	mY /= GetLength();
	mZ /= GetLength();
}

Vector3 Vector3::Normalized()
{
	return Vector3(
		mX / GetLength(), 
		mY / GetLength(), 
		mZ / GetLength());
}

Vector3 Vector3::operator+(const Vector3& source) const
{
	return Vector3(*this) += source;
}

Vector3 Vector3::operator-(const Vector3& source) const
{
	return Vector3(*this) -= source;
}

Vector3 Vector3::operator*(const int value) const
{
	return Vector3(*this) *= value;
}

Vector3 Vector3::operator+=(const Vector3& source)
{
	mX += source.mX;
	mY += source.mY;
	mZ += source.mZ;
	return *this;
}

Vector3 Vector3::operator-=(const Vector3& source)
{
	mX -= source.mX;
	mY -= source.mY;
	mZ -= source.mZ;
	return *this;
}

Vector3 Vector3::operator*=(const int value)
{
	mX *= value;
	mY *= value;
	mZ *= value;
	return *this;
}

bool Vector3::operator==(const Vector3& source) const
{
	return ((mX == source.mX) && (mY == source.mY) && (mZ == source.mZ));
}