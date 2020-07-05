#include "Case.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

Vec diff(Vec& T) {
	Vec tmp(0.0, T.size());
	for (size_t i = 1; i < T.size() - 2; i++)
	{
		tmp[i] = T[i + 1] + T[i - 1] - 2 * T[i];
	}
	return tmp;
}

Case::Case(int N, double L)
{
	Lx = L;
	NumPoint = N;
	h = L / N;
	dt = h * h / 4.0;
	T = Vec(0.0, NumPoint);
	dT = Vec(0.0, NumPoint);
};
void Case::step()
{
	double  tay = dt / (h*h);
	dT = diff(T);
	T = T + dT * tay;
};
void Case::setInitial(Vec T_in)
{
	T = T_in;
};
void Case::write(std::string name)
{
	ofstream out;
	out.open(name);
	out <<setw(15) << "x";
	out <<setw(15) << "T";
	out <<endl;
	for (int i = 0; i < NumPoint; i++) {
		out <<setw(15) << i * h;
		out <<setw(15) << T[i];
		out <<endl;
	}
};
