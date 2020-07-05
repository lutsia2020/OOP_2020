#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols)
{
	allocSpace();
	for (int i = 0; i < rows_ * cols_; i++)
		p[i] = 0;
}

Matrix::Matrix() : rows_(1), cols_(1)
{
	allocSpace();
	p[0] = 0;
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows_ * cols_; i++) {
		p[i] = 0;
	}
	cols_ = 0;
	rows_ = 0;
	delete[] p;
}

Matrix::Matrix(const Matrix& m) : rows_(m.rows_), cols_(m.cols_)
{
	allocSpace();
	for (int i = 0; i < rows_ * cols_; i++)
		p[i] = m.p[i];
}

Matrix& Matrix::operator=(const Matrix& m)
{
	if (this == &m) {
		return *this;
	}

	if (rows_ != m.rows_ || cols_ != m.cols_) {
		delete[] p;

		rows_ = m.rows_;
		cols_ = m.cols_;
		allocSpace();
	}

	for (int i = 0; i < rows_ * cols_; i++)
		p[i] = m.p[i];
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& m)
{
	for (int i = 0; i < rows_ * cols_; i++)
		p[i] += m.p[i];
	return *this;
}

Matrix & Matrix::operator+=(double num)
{
	for (int i = 0; i < rows_ * cols_; i++)
		p[i] += num;
	return *this;
}

Matrix & Matrix::operator-=(double num)
{
	for (int i = 0; i < rows_ * cols_; i++)
		p[i] -= num;
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m)
{
	for (int i = 0; i < rows_ * cols_; i++)
		p[i] -= m.p[i];
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& m)
{
	if (rows_ * cols_ != m.rows_ * m.cols_)
	{
		throw exception("different num of elemets");
	}

	Matrix temp(rows_, cols_);

	for (int i = 0; i < rows_ * cols_; i++)
		temp.p[i] = p[i] * m.p[i];

	return (*this = temp);
}

Matrix& Matrix::operator*=(double num)
{
	for (int i = 0; i < rows_ * cols_; i++)
		p[i] *= num;
	return *this;
}

Matrix& Matrix::operator/=(double num)
{
	for (int i = 0; i < rows_ * cols_; i++) {
		p[i] /= num;
	}
	return *this;
}

Matrix& Matrix::operator/=(const Matrix& m) {
	Matrix temp(rows_, m.cols_);
	for (int i = 0; i < rows_ * cols_; i++) {
		temp.p[i] = p[i] / m.p[i];
	}
	return (*this = temp);
}

void Matrix::allocSpace()
{
	p = new double[rows_ * cols_];
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	Matrix temp(m1);
	return (temp += m2);
}

Matrix operator+(const Matrix & m, double num)
{
	Matrix temp = Matrix(m);
	return(temp += num);
}

Matrix operator+(double num, const Matrix & m)
{
	Matrix temp = Matrix(m);
	return(temp += num);
}

Matrix operator-(const Matrix & m, double num)
{
	Matrix temp = Matrix(m);
	return(temp -= num);
}

Matrix operator-(double num, const Matrix & m)
{
	return m.number_subtraction(num, m);
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
	Matrix temp(m1);
	return (temp -= m2);
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
	Matrix temp(m1);
	return (temp *= m2);
}

Matrix operator*(const Matrix& m, double num)
{
	Matrix temp(m);
	return (temp *= num);
}

Matrix operator*(double num, const Matrix& m)
{
	return (m * num);
}

Matrix operator/(const Matrix& m, double num)
{
	Matrix temp(m);
	return (temp /= num);
}

Matrix operator/(const Matrix& m1, const Matrix& m2) {
	Matrix temp(m1);
	return (temp /= m2);
}

Matrix operator/(double num, const Matrix& m)
{
	return m.number_devision(num, m);
}

Matrix Matrix::number_devision(double num, const Matrix & m)
{
	Matrix temp = Matrix(m);
	for (int i = 0; i < m.rows_ * m.cols_; i++)
		temp.p[i] = num / m.p[i];

	return temp;
}

Matrix Matrix::number_subtraction(double num, const Matrix & m)
{
	Matrix temp = Matrix(m);
	for (int i = 0; i < m.rows_ * m.cols_; i++)
		temp.p[i] = num - m.p[i];

	return temp;
}

ostream& operator<<(ostream& os, const Matrix& m)
{
	string sep;

	for (int i = 0; i < m.cols_; i++)
		sep += "--------";

	os << sep << endl;
	for (int i = 0; i < m.rows_; i++)
	{
		for (int j = 0; j < m.cols_; j++)
			os << m.p[i * m.rows_ + j] << "\t";
		os << endl;
	}
	os << sep << endl << endl;

	return os;
}
