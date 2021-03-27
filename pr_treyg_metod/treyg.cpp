#include <iostream>
using namespace std;
double func(double x)
{
	return exp(-x) * sin(2 * x);
}
double func1(double a, double z, double h)
{
	int n = 1; double I = 0.0;
	while (n < (z-1))
	{
		I += h * func((a + h / 2 + n * h));
		n++;
	}
	return I;
}
int main()
{
	double a, b, h0, h1, E, z, z1;
	int p;
	a = 0; b = 2; h0 = 0.5; h1 = h0 / 2; z = (b - a) / h0; z1 = (b - a) / h1; E = 0.0001; p = 1;
	double R, I1, I2, I, Isum;
	R = 1; I1 = 0; I2 = 0; Isum = 1;
	I1 = func1(a, z, h0);
	I2 = func1(a, z1, h1);
	Isum = I2 - I1;
	while (abs(R) >= E)
	{
		R = (Isum) / (2 ^ p - 1);
		p++;
	}
	I = I2 + R;
	cout << "Integral: " << I << " Ih/2: " << I2 << " Ih: " << I1 << " R: " << R;
}