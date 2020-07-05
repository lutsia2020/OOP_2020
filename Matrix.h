#pragma once
class Matrix {
public:
	Matrix(int, int);
	Matrix();
	~Matrix();
	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);

	inline double& operator()(int x, int y) { return p[x * cols_ + y]; }

	Matrix& operator+=(const Matrix&);
	Matrix& operator+=(double);
	Matrix& operator-=(double);
	Matrix& operator-=(const Matrix&);
	Matrix& operator*=(const Matrix&);
	Matrix& operator*=(double);
	Matrix& operator/=(double);
	Matrix& operator/=(const Matrix&);
	static Matrix number_devision(double num, const Matrix&);
	static Matrix number_subtraction(double num, const Matrix&);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& dt);

private:
	int rows_, cols_;
	double *p;

	void allocSpace();
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator+(const Matrix&, double);
Matrix operator+(double, const Matrix&);
Matrix operator-(const Matrix&, double);
Matrix operator-(double, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);
Matrix operator/(const Matrix&, double);
Matrix operator/(const Matrix&, const Matrix&);
Matrix operator/(double, const Matrix&);
