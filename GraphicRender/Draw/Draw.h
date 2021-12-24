#pragma once

#include <algorithm>
#include <vector>
#include <windows.h>

#include "Vector2.h"
#include "Utility.h"

void DrawLine(HDC hDC, const Vector2& v1, const Vector2& v2, COLORREF color);
void DrawLine(HDC hDC, const float x1, const float y1, const float x2, const float y2, COLORREF color);

void DrawCircle(HDC hDC, const Vector2& center, const float radius, COLORREF color);
void DrawCircle(HDC hDC, const float x, const float y, const float radius, COLORREF color);

void DrawRectangle(HDC hDC, const Vector2& lb, const Vector2& rt, const Vector2& lt, const Vector2& rb, COLORREF color);
void DrawRectangle(HDC hDC, const Vector2& leftBottom, const Vector2& rightTop, COLORREF color);
void DrawRectangle(HDC hDC, const float left, const float bottom, const float right, const float top, COLORREF color);

void DrawCoordinate(HDC hDC, int leftX, int rightX, int upY, int downY, COLORREF color);