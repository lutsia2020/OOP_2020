#pragma once
#include <valarray>
#include <string>
using namespace std;
using vec = valarray<double>;

class Case
{
public:
	int NumPoint;
	double Lx;
	double dt;
	double h;
	double NuDivHH;
	double HiDivHH;
	double param;
	vec T;
	vec dT;
	vec v;
	vec dv;

	Case(int NumPoint, double L, double Nu, double Hi, double dP, double r);
	void SetInitial(vec T, vec v);
	void step();
	void write(string adr);
};
