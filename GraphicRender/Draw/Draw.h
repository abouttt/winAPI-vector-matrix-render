#pragma once

#include <vector>
#include <algorithm>

#include <windows.h>
#include "Vector2.h"

float GetXEquationOfLine(const Vector2& v1, const Vector2& v2, const float x);
float GetYEquationOfLine(const Vector2& v1, const Vector2& v2, const float y);
void DrawLine(HDC hdc, const Vector2& startPoint, const Vector2& endPoint, COLORREF color);
void DrawLine(HDC hdc, float startX, float startY, float endX, float endY, COLORREF color);