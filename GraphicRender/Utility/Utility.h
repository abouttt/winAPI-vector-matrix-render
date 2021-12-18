#pragma once

#include <windows.h>

constexpr float PI = 3.14159265359f;

float Rad2Deg(float radian);
float Deg2Rad(float degree);

void SetCartesianCoordinateSystem(HDC hDC, HWND hWnd);