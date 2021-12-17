#pragma once

#include <vector>
#include <algorithm>

#include <windows.h>
#include "Vector2.h"

void DrawLine(HDC hDC, const Vector2& v1, const Vector2& v2, COLORREF color);
void DrawLine(HDC hDC, float startX, float startY, float endX, float endY, COLORREF color);
void DrawCircle(HDC hDC, const Vector2& center, float radius, COLORREF color);
void DrawCircle(HDC hDC, float x, float y, float radius, COLORREF color);