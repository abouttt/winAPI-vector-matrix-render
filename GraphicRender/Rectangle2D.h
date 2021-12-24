#pragma once

#include "Draw.h"
#include "Matrix.h"
#include "Vector2.h"

class Rectangle2D
{
public:
	Rectangle2D(const float left, const float bottom, const float right, const float top);
	Rectangle2D(const Vector2& leftBottom, const Vector2& rightTop);

	void Translate(float x, float y);
	void Scaling(float x, float y);
	void Rotate(float degree);

	void Draw(HDC hDC, COLORREF color);

private:
	Vector2 getCenterPos() const;

private:
	Vector2 mLB;
	Vector2 mRT;
	Vector2 mLT;
	Vector2 mRB;
	float mTranslateX;
	float mTranslateY;
};