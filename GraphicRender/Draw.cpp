#include "Draw.h"

float GetXEquationOfLine(const Vector2& v1, const Vector2& v2, const float x)
{
	return (v2.GetY() - v1.GetY()) / (v2.GetX() - v1.GetX()) * (x - v1.GetX()) + v1.GetY();
}

float GetYEquationOfLine(const Vector2& v1, const Vector2& v2, const float y)
{
	return (v2.GetX() - v1.GetX()) / (v2.GetY() - v1.GetY()) * (y - v1.GetY()) + v1.GetX();
}

void SetXLineCoord(std::vector<Vector2>* const outPoints, const Vector2& startPoint, const Vector2& endPoint)
{
	for (int index = 0; index < outPoints->size(); index++)
	{
		(*outPoints)[index].SetX(startPoint.GetX() + index);
		(*outPoints)[index].SetY(GetXEquationOfLine(startPoint, endPoint, (*outPoints)[index].GetX()));
	}
}

void SetYLineCoord(std::vector<Vector2>* const outPoints, const Vector2& startPoint, const Vector2& endPoint)
{
	for (int index = 0; index < outPoints->size(); index++)
	{
		(*outPoints)[index].SetY(startPoint.GetY() + index);
		(*outPoints)[index].SetX(GetYEquationOfLine(startPoint, endPoint, (*outPoints)[index].GetY()));
	}
}

void DrawLine(HDC hdc, const Vector2& startPoint, const Vector2& endPoint, COLORREF color)
{
	int xLength = (int)std::fabsf(endPoint.GetX() - startPoint.GetX());
	int yLength = (int)std::fabsf(endPoint.GetY() - startPoint.GetY());
	int finalLength = xLength;
	void(*pSetLineCoordFcn)(std::vector<Vector2>*const, const Vector2&, const Vector2&) = SetXLineCoord;

	if (xLength < yLength)
	{
		finalLength = yLength;
		pSetLineCoordFcn = SetYLineCoord;
	}

	std::vector<Vector2> points(finalLength);
	pSetLineCoordFcn(&points, startPoint, endPoint);
	for (auto& v : points)
	{
		SetPixel(hdc, (int)v.GetX(), (int)v.GetY(), color);
	}
}