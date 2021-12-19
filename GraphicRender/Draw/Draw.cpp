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
	float xLength = std::fabsf(v2.GetX() - v1.GetX());
	float yLength = std::fabsf(v2.GetY() - v1.GetY());

	if (xLength > yLength)
	{
		outPoints->resize((int)xLength);
		for (std::vector<int>::size_type i = 0; i < outPoints->size(); i++)
		{
			(*outPoints)[i].SetX((float)i);
			(*outPoints)[i].SetY(GetYEquationOfLine(v1, v2, (*outPoints)[i].GetX()));
		}
	}
	else
	{
		outPoints->resize((int)yLength);
		for (std::vector<int>::size_type i = 0; i < outPoints->size(); i++)
		{
			(*outPoints)[i].SetY((float)i);
			(*outPoints)[i].SetX(GetXEquationOfLine(v1, v2, (*outPoints)[i].GetY()));
		}
	}
}

void SetCircleCoord(std::vector<Vector2>* const outPoints, const Vector2& center, float radius)
{
	for (std::vector<int>::size_type degree = 0; degree < outPoints->size(); degree++)
	{
		(*outPoints)[degree].SetX(center.GetX() + radius * cosf(Deg2Rad((float)degree)));
		(*outPoints)[degree].SetY(center.GetY() + radius * sinf(Deg2Rad((float)degree)));
	}
}

void DrawLine(HDC hDC, const Vector2& v1, const Vector2& v2, COLORREF color)
{
	std::vector<Vector2> points;
	SetLineCoord(&points, v1, v2);
	for (const auto& v : points)
	{
		SetPixel(hDC, (int)v.GetX(), (int)v.GetY(), color);
	}
}

void DrawLine(HDC hDC, const float x1, const float y1, const float x2, const float y2, COLORREF color)
{
	std::vector<Vector2> points;
	Vector2 v1(x1, y1);
	Vector2 v2(x2, y2);
	SetLineCoord(&points, v1, v2);
	for (const auto& v : points)
	{
		SetPixel(hDC, (int)v.GetX(), (int)v.GetY(), color);
	}
}

void DrawCircle(HDC hDC, const Vector2& center, const float radius, COLORREF color)
{
	float radian;
	float x;
	float y;
	for (float degree = 0.0f; degree < 360.0f; degree += 0.1f)
	{
		radian = Deg2Rad(degree);
		x = center.GetX() + radius * cosf(radian);
		y = center.GetY() + radius * sinf(radian);
		SetPixel(hDC, (int)x, (int)y, color);
	}
}

void DrawCircle(HDC hDC, const float x, const float y, const float radius, COLORREF color)
{
	std::vector<Vector2> points(360);
	Vector2 center(x, y);
	SetCircleCoord(&points, center, radius);
	for (const auto& v : points)
	{
		SetPixel(hDC, (int)v.GetX(), (int)v.GetY(), color);
	}
}