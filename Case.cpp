#include "Case.h"
#include <fstream>
#include <iomanip>
using namespace std;

Case::Case(int N, double L, double Nu, double Hi, double dP, double r)
{
	Lx = L;
	NumPoint = N;
	h = L / N;
	T = vec(0.0, N);
	v = vec(0.0, N);
	dT = vec(0.0, N);
	dv = vec(0.0, N);
	dt = h * h / 4.0;
	HiDivHH = Hi / (h * h);
	NuDivHH = Nu / (h * h);
	param = dP / r;
}

void Case::SetInitial(vec _T, vec _v)
{
	T = _T;
	v = _v;
}


void diff(vec& T, vec& dT)
{
	for (size_t i = 1; i < T.size() - 2; ++i)
		dT[i] = T[i + 1] + T[i - 1] - 2 * T[i];
}



void Case::step()
{
	double dth = dt * h;
	diff(v, dv);
	v = v + dt * (dv * NuDivHH - param);
	diff(T, dT);
	T = T + dt * (HiDivHH * dT + v * (T.shift(-1) - T.shift(1)) / (2 * h));
}

void Case::write(string adr)
{
	ofstream out;
	out.open(adr);

	out << setw(5) << "x";
	out << setw(15) << "v";
	out << setw(15) << "T";
	out << endl;
	for (int i = 0; i < NumPoint; i++)
	{
		out << setw(5) << i * h;
		out << setw(15) << v[i];
		out << setw(15) << T[i];
		out << endl;
	}
	out.close();
}
