#include "Utility.h"

float Rad2Deg(const float radian)
{
	return radian * 180 / PI;
}

float Deg2Rad(const float degree)
{
	return degree * PI / 180;
}

void SetCartesianCoordinateSystem(HDC hDC, HWND hWnd)
{
    RECT clientRect;
    GetClientRect(hWnd, &clientRect);
    SetMapMode(hDC, MM_LOMETRIC);
    SetViewportOrgEx(hDC, (int)(clientRect.right * 0.5f), (int)(clientRect.bottom * 0.5f), NULL);
}