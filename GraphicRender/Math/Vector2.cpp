#include "Vector2.h"

Vector2::Vector2(float x, float y)
	: mX(x)
	, mY(y)
{
}

Vector2 Vector2::Get() const
{
	return Vector2(*this);
}

float Vector2::GetX() const
{
	return mX;
}

float Vector2::GetY() const
{
	return mY;
}

void Vector2::Set(const float x, const float y)
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

float Vector2::Dot(const Vector2& left, const Vector2& right)
{
	return (left.mX * right.mX) + (left.mY * right.mY);
}

void Vector2::Normalize()
{
	mX /= GetLength();
	mY /= GetLength();
}

Vector2 Vector2::Normalized()
{
	return Vector2(mX / GetLength(), mY / GetLength());
}

Vector2 Vector2::operator+(const Vector2& source) const
{
	return Vector2(*this) += source;
}

Vector2 Vector2::operator-(const Vector2& source) const
{
	return Vector2(*this) -= source;
}

Vector2 Vector2::operator*(const int value) const
{
	return Vector2(*this) *= value;
}

Vector2 Vector2::operator+=(const Vector2& source)
{
	mX += source.mX;
	mY += source.mY;
	return *this;
}

Vector2 Vector2::operator-=(const Vector2& source)
{
	mX -= source.mX;
	mY -= source.mY;
	return *this;
}

Vector2 Vector2::operator*=(const int value)
{
	mX *= value;
	mY *= value;
	return *this;
}

bool Vector2::operator==(const Vector2& source) const
{
	return ((mX == source.mX) && (mY == source.mY));
}