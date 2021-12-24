#include "Rectangle2D.h"

Rectangle2D::Rectangle2D(const float left, const float bottom, const float right, const float top)
	: mLB(left, bottom)
	, mRT(right, top)
	, mLT(left, top)
	, mRB(right, bottom)
	, mTranslateX(0)
	, mTranslateY(0)
{
	Vector2 centerPos = getCenterPos();
	mTranslateX = centerPos.GetX();
	mTranslateY = centerPos.GetY();
	Translate(-centerPos.GetX(), -centerPos.GetY());
}

Rectangle2D::Rectangle2D(const Vector2& leftBottom, const Vector2& rightTop)
	: mLB(leftBottom)
	, mRT(rightTop)
	, mLT(leftBottom.GetX(), rightTop.GetY())
	, mRB(rightTop.GetX(), leftBottom.GetY())
	, mTranslateX(0)
	, mTranslateY(0)
{
	Vector2 centerPos = getCenterPos();
	mTranslateX = centerPos.GetX();
	mTranslateY = centerPos.GetY();
	Translate(-centerPos.GetX(), -centerPos.GetY());
}

void Rectangle2D::Translate(float x, float y)
{
	mTranslateX += x;
	mTranslateY += y;

	Matrix translateMatrix = Matrix::GetTranslateMatrix2D(x, y);

	Vector2* vectorPtr[4] = { &mLB, &mRT, &mLT, &mRB };
	Matrix temp(3, 1);
	Matrix result(3, 1);

	for (int i = 0; i < 4; i++)
	{
		temp.At(0, 0) = vectorPtr[i]->GetX();
		temp.At(1, 0) = vectorPtr[i]->GetY();
		temp.At(2, 0) = 1;

		result = translateMatrix * temp;
		vectorPtr[i]->SetVector(result.At(0, 0), result.At(1, 0));
	}
}

void Rectangle2D::Scaling(float x, float y)
{
	float tempX = mTranslateX;
	float tempY = mTranslateY;

	Matrix scaleMatrix = Matrix::GetScaleMatrix2D(x, y);
	Matrix translateMatrixCenter = Matrix::GetTranslateMatrix2D(-tempX, -tempY);
	Matrix translateMatrixReturn = Matrix::GetTranslateMatrix2D(tempX, tempY);

	Vector2* vectorPtr[4] = { &mLB, &mRT, &mLT, &mRB };
	Matrix temp(3, 1);
	Matrix result(3, 1);

	for (int i = 0; i < 4; i++)
	{
		temp.At(0, 0) = vectorPtr[i]->GetX();
		temp.At(1, 0) = vectorPtr[i]->GetY();
		temp.At(2, 0) = 1;

		result = (translateMatrixReturn * scaleMatrix * translateMatrixCenter) * temp;
		vectorPtr[i]->SetVector(result.At(0, 0), result.At(1, 0));
	}
}

void Rectangle2D::Rotate(float degree)
{
	float tempX = mTranslateX;
	float tempY = mTranslateY;

	Matrix rotateZMatrix = Matrix::GetRotationMatrix2D(degree);
	Matrix translateMatrixCenter = Matrix::GetTranslateMatrix2D(-tempX, -tempY);
	Matrix translateMatrixReturn = Matrix::GetTranslateMatrix2D(tempX, tempY);

	Vector2* vectorPtr[4] = { &mLB, &mRT, &mLT, &mRB };
	Matrix temp(3, 1);
	Matrix result(3, 1);

	for (int i = 0; i < 4; i++)
	{
		temp.At(0, 0) = vectorPtr[i]->GetX();
		temp.At(1, 0) = vectorPtr[i]->GetY();
		temp.At(2, 0) = 1;

		result = (translateMatrixReturn * rotateZMatrix * translateMatrixCenter) * temp;
		vectorPtr[i]->SetVector(result.At(0, 0), result.At(1, 0));
	}
}

void Rectangle2D::Draw(HDC hDC, COLORREF color)
{
	DrawRectangle(hDC, mLB, mRT, mLT, mRB, color);
}

Vector2 Rectangle2D::getCenterPos() const
{
	return Vector2((mLB.GetX() + mRB.GetX()) * 0.5f, (mLB.GetY() + mLT.GetY()) * 0.5f);
}