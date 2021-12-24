#include "Matrix.h"

Matrix::Matrix(const size_t rows, const size_t cols)
	: mRows(rows)
	, mCols(cols)
	, mData(rows, std::vector<float>(cols, 0))
{
	assert(rows > 0);
	assert(cols > 0);
}

Matrix::Matrix(const size_t rows, const size_t cols, const float scalar)
	: mRows(rows)
	, mCols(cols)
	, mData(rows, std::vector<float>(cols, scalar))
{
	assert(rows > 0);
	assert(cols > 0);
}

Matrix::Matrix(const Matrix& ref)
	: mRows(ref.mRows)
	, mCols(ref.mCols)
	, mData(ref.mData)
{
}

Matrix::Matrix(Matrix&& ref) noexcept
	: mRows(ref.mRows)
	, mCols(ref.mCols)
	, mData(ref.mData)
{
}

size_t Matrix::GetRows() const
{
	return mRows;
}

size_t Matrix::GetCols() const
{
	return mCols;
}

float& Matrix::At(size_t rows, size_t cols)
{
	return mData[rows][cols];
}

const float& Matrix::At(const size_t rows, const size_t cols) const
{
	return mData[rows][cols];
}

void Matrix::Swap(Matrix& other)
{
	std::swap(mRows, other.mRows);
	std::swap(mCols, other.mCols);
	std::swap(mData, other.mData);
}

void Matrix::Fill(const float scalar)
{
	std::fill(mData.begin(), mData.end(), std::vector<float>(mRows, scalar));
}

bool Matrix::IsSquareMatrix()
{
	return mRows == mCols;
}

void Matrix::SetIdentity()
{
	assert(mRows == mCols);

	for (size_t row = 0; row < mRows; row++)
	{
		for (size_t col = 0; col < mCols; col++)
		{
			if (row == col)
			{
				mData[row][col] = 1.0f;
			}
			else
			{
				mData[row][col] = 0.0f;
			}
		}
	}
}

bool Matrix::IsIdentity()
{
	assert(mRows == mCols);

	Matrix temp(mRows, mCols);
	temp.SetIdentity();

	return mData == temp.mData;
}

Matrix Matrix::Transpose() const
{
	Matrix result(mCols, mRows);

	for (size_t row = 0; row < mRows; row++)
	{
		for (size_t col = 0; col < mCols; col++)
		{
			result.mData[col][row] = mData[row][col];
		}
	}

	return result;
}

float Matrix::GetDeterminant() const
{
	assert(mRows == mCols);

	if (mRows == 2)
	{
		return (mData[0][0] * mData[1][1]) - (mData[0][1] * mData[1][0]);
	}

	float det = 0;
	int sign = 1;
	for (size_t col = 0; col < mCols; col++)
	{
		Matrix submatrix = getSubmatrix(0, col);
		det += sign * mData[0][col] * submatrix.GetDeterminant();
		sign *= -1;
	}

	return det;
}

Matrix Matrix::GetInversMatrix()
{
	assert(mRows == mCols);

	size_t n = mRows;

	Matrix result(n, n);
	Matrix adj(n, n);
	float det = GetDeterminant();

	if (n == 2)
	{
		adj.mData[0][0] = mData[1][1];
		adj.mData[1][1] = mData[0][0];
		adj.mData[0][1] = -mData[0][1];
		adj.mData[1][0] = -mData[1][0];

		for (size_t row = 0; row < mRows; row++)
		{
			for (size_t col = 0; col < mCols; col++)
			{
				result.mData[row][col] = (1 / det) * adj.mData[row][col];
			}
		}

		return result;
	}

	adj = getAdjointMatrix();

	for (size_t row = 0; row < mRows; row++)
	{
		for (size_t col = 0; col < mCols; col++)
		{
			result.mData[row][col] = (1 / det) * adj.mData[row][col];
		}
	}

	return result;
}

Matrix Matrix::GetTranslateMatrix2D(const float x, const float y)
{
	Matrix result(3, 3);

	result.SetIdentity();
	result.At(0, 2) = x;
	result.At(1, 2) = y;

	return result;
}

Matrix Matrix::GetTranslateMatrix3D(const float x, const float y, const float z)
{
	Matrix result(4, 4);

	result.SetIdentity();
	result.At(0, 3) = x;
	result.At(1, 3) = y;
	result.At(2, 3) = z;

	return result;
}

Matrix Matrix::GetScaleMatrix2D(const float x, const float y)
{
	Matrix result(3, 3);

	result.SetIdentity();
	result.At(0, 0) = x;
	result.At(1, 1) = y;

	return result;
}

Matrix Matrix::GetScaleMatrix3D(const float x, const float y, const float z)
{
	Matrix result(4, 4);

	result.SetIdentity();
	result.At(0, 0) = x;
	result.At(1, 1) = y;
	result.At(2, 2) = z;

	return result;
}

Matrix Matrix::GetRotationMatrix2D(const float degree)
{
	float radian = Deg2Rad(degree);
	Matrix result(3, 3);

	result.SetIdentity();
	result.At(0, 0) = cos(radian);
	result.At(0, 1) = sin(radian);
	result.At(1, 0) = -sin(radian);
	result.At(1, 1) = cos(radian);

	return result;
}

Matrix Matrix::GetRotationXMatrix3D(const float degree)
{
	float radian = Deg2Rad(degree);
	Matrix result(4, 4);

	result.SetIdentity();
	result.At(1, 1) = cos(radian);
	result.At(1, 2) = -sin(radian);
	result.At(2, 1) = sin(radian);
	result.At(2, 2) = cos(radian);

	return result;
}

Matrix Matrix::GetRotationYMatrix3D(const float degree)
{
	float radian = Deg2Rad(degree);
	Matrix result(4, 4);

	result.SetIdentity();
	result.At(0, 0) = cos(radian);
	result.At(0, 2) = sin(radian);
	result.At(2, 0) = -sin(radian);
	result.At(2, 2) = cos(radian);

	return result;
}

Matrix Matrix::GetRotationZMatrix3D(const float degree)
{
	float radian = Deg2Rad(degree);
	Matrix result(4, 4);

	result.SetIdentity();
	result.At(0, 0) = cos(radian);
	result.At(0, 1) = sin(radian);
	result.At(1, 0) = -sin(radian);
	result.At(1, 1) = cos(radian);

	return result;
}

Matrix Matrix::operator+(const Matrix& other) const
{
	return Matrix(*this) += other;
}

Matrix Matrix::operator-(const Matrix& other) const
{
	return Matrix(*this) -= other;
}

Matrix Matrix::operator*(const Matrix& other) const
{
	assert(mCols == other.mRows);

	Matrix result(mRows, other.mCols);

	for (size_t row = 0; row < mRows; row++)
	{
		for (size_t col = 0; col < other.mCols; col++)
		{
			for (size_t index = 0; index < mCols; index++)
			{
				result.mData[row][col] += mData[row][index] * other.mData[index][col];
			}
		}
	}
	return result;
}

Matrix Matrix::operator*(const float scalar) const
{
	return Matrix(*this) *= scalar;
}

Matrix Matrix::operator/(const float scalar) const
{
	return Matrix(*this) /= scalar;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	assert(mRows == other.mRows);
	assert(mCols == other.mCols);

	for (size_t row = 0; row < mRows; row++)
	{
		for (size_t col = 0; col < mCols; col++)
		{
			mData[row][col] += other.mData[row][col];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	assert(mRows == other.mRows);
	assert(mCols == other.mCols);

	for (size_t row = 0; row < mRows; row++)
	{
		for (size_t col = 0; col < mCols; col++)
		{
			mData[row][col] -= other.mData[row][col];
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	return *this = (*this) * other;
}

Matrix& Matrix::operator*=(const float scalar)
{
	for (size_t row = 0; row < mRows; row++)
	{
		for (size_t col = 0; col < mCols; col++)
		{
			mData[row][col] *= scalar;
		}
	}
	return *this;
}

Matrix& Matrix::operator/=(const float scalar)
{
	for (size_t row = 0; row < mRows; row++)
	{
		for (size_t col = 0; col < mCols; col++)
		{
			mData[row][col] /= scalar;
		}
	}
	return *this;
}

bool Matrix::operator==(const Matrix& other) const
{
	return mData == other.mData;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	mData = other.mData;
	return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept
{
	mData = other.mData;
	return *this;
}

Matrix operator*(const float scalar, const Matrix& matrix)
{
	return matrix * scalar;
}

Matrix operator/(const float scalar, const Matrix& matrix)
{
	return matrix / scalar;
}

Matrix Matrix::getSubmatrix(const size_t rows, const size_t cols) const
{
	assert(mRows == mCols);

	size_t n = mRows;
	Matrix result(n - 1, n - 1);
	int subRow = 0;
	int subCol = 0;

	for (size_t row = 0; row < n; row++)
	{
		for (size_t col = 0; col < n; col++)
		{
			if (row != rows && col != cols)
			{
				result.mData[subRow][subCol++] = mData[row][col];
				if (subCol == n - 1)
				{
					subCol = 0;
					subRow++;
				}
			}
		}
	}

	return result;
}

Matrix Matrix::getCofactorMatrix()
{
	assert(mRows == mCols);

	Matrix result(mRows, mCols);
	int sign = 1;

	for (size_t row = 0; row < mRows; row++)
	{
		for (size_t col = 0; col < mCols; col++)
		{
			result.mData[col][row] = sign * getSubmatrix(row, col).GetDeterminant();
			sign *= -1;
		}
	}

	return result;
}

Matrix Matrix::getAdjointMatrix()
{
	assert(mRows == mCols);

	Matrix result(mRows, mCols);

	result = getCofactorMatrix();
	result.Transpose();

	return result;
}