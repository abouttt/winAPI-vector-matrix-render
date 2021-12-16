#pragma once

#include <vector>

#include "framework.h"
#include "Vector2.h"

float GetXEquationOfLine(const Vector2& v1, const Vector2& v2, const float x);
float GetYEquationOfLine(const Vector2& v1, const Vector2& v2, const float y);
void SetXLineCoord(std::vector<Vector2>* const outPoints, const Vector2& startPoint, const Vector2& endPoint);
void SetYLineCoord(std::vector<Vector2>* const outPoints, const Vector2& startPoint, const Vector2& endPoint);
void DrawLine(HDC hdc, const Vector2& startPoint, const Vector2& endPoint, COLORREF color);