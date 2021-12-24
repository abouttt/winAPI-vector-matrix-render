#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

#include "Utility.h"

class Matrix
{
public:
	Matrix() = delete;
	Matrix(const size_t rows, const size_t cols);
	Matrix(const size_t rows, const size_t cols, const float scalar);
	Matrix(const Matrix& ref);
	Matrix(Matrix&& ref) noexcept;
	~Matrix() = default;

	size_t GetRows() const;
	size_t GetCols() const;

	float& At(const size_t rows, const size_t cols);
	const float& At(const size_t rows, const size_t cols) const;

	void Swap(Matrix& other);
	void Fill(const float scalar);
	bool IsSquareMatrix();
	void SetIdentity();
	bool IsIdentity();
	Matrix Transpose() const;
	float GetDeterminant() const;
	Matrix GetInversMatrix();

	static Matrix GetTranslateMatrix2D(const float x, const float y);
	static Matrix GetTranslateMatrix3D(const float x, const float y, const float z);

	static Matrix GetScaleMatrix2D(const float x, const float y);
	static Matrix GetScaleMatrix3D(const float x, const float y, const float z);

	static Matrix GetRotationMatrix2D(const float degree);
	static Matrix GetRotationXMatrix3D(const float degree);
	static Matrix GetRotationYMatrix3D(const float degree);
	static Matrix GetRotationZMatrix3D(const float degree);

	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix operator*(const float scalar) const;
	Matrix operator/(const float scalar) const;

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(const float scalar);
	Matrix& operator/=(const float scalar);

	bool operator==(const Matrix& other) const;
	Matrix& operator=(const Matrix& other);
	Matrix& operator=(Matrix&& other) noexcept;

private:
	Matrix getSubmatrix(const size_t rows, const size_t cols) const;
	Matrix getCofactorMatrix();
	Matrix getAdjointMatrix();

private:
	size_t mRows;
	size_t mCols;
	std::vector<std::vector<float>> mData;
};

static Matrix operator*(const float scalar, const Matrix& matrix);
static Matrix operator/(const float scalar, const Matrix& matrix);