#include "Draw.h"

float GetYEquationOfLine(const Vector2& v1, const Vector2& v2, const float x)
{
	return (v2.GetY() - v1.GetY()) / (v2.GetX() - v1.GetX()) * (x - v1.GetX()) + v1.GetY();
}

float GetXEquationOfLine(const Vector2& v1, const Vector2& v2, const float y)
{
	return (v2.GetX() - v1.GetX()) / (v2.GetY() - v1.GetY()) * (y - v1.GetY()) + v1.GetX();
}

void SetLineCoord(std::vector<Vector2>* const outPoints, const Vector2& v1, const Vector2& v2)
{
	int xLength = (int)std::fabsf(v2.GetX() - v1.GetX());
	int yLength = (int)std::fabsf(v2.GetY() - v1.GetY());

	if (xLength > yLength)
	{
		outPoints->resize(xLength);
		for (std::vector<Vector2>::size_type index = 0; index < outPoints->size(); index++)
		{
			(*outPoints)[index].SetX(v1.GetX() + index);
			(*outPoints)[index].SetY(GetYEquationOfLine(v1, v2, (*outPoints)[index].GetX()));
		}
	}
	else
	{
		outPoints->resize(yLength);
		for (std::vector<Vector2>::size_type index = 0; index < outPoints->size(); index++)
		{
			(*outPoints)[index].SetY(v1.GetY() + index);
			(*outPoints)[index].SetX(GetXEquationOfLine(v1, v2, (*outPoints)[index].GetY()));
		}
	}
}

void DrawLine(HDC hdc, const Vector2& v1, const Vector2& v2, COLORREF color)
{
	std::vector<Vector2> points;
	SetLineCoord(&points, v1, v2);
	for (const auto& v : points)
	{
		SetPixel(hdc, (int)v.GetX(), (int)v.GetY(), color);
	}
}

void DrawLine(HDC hdc, float startX, float startY, float endX, float endY, COLORREF color)
{
	std::vector<Vector2> points;
	Vector2 v1(startX, startY);
	Vector2 v2(endX, endY);
	SetLineCoord(&points, v1, v2);
	for (const auto& v : points)
	{
		SetPixel(hdc, (int)v.GetX(), (int)v.GetY(), color);
	}
}