#include <iostream>
#include <fstream>
#include "GaussPolynom.h"

using namespace std;

#define X0 0
#define STEP 0.5
#define N 100
#define FUNC abs

double sqr(double x){ return x*x; }

void CreateInterpolationNodes(double(function(double)), double x0, double step, int n, DArray &x, DArray &y)
{
	x = DArray(n);
	y = DArray(n);

	double current = x0 - step*n;
	for (int i = -n; i < n + 1; i++, current += step)
	{
		x[i] = current;
		y[i] = function(current);
	}
}

double Error(double actual, double expected)
{
	return abs(actual - expected);
}

int main()
{
	DArray x;
	DArray y;
	CreateInterpolationNodes(FUNC, X0, STEP, N, x, y);

	GaussPolynom poly(x, y, N);
	cout << endl;
	for (double i = -10; i < 10; i += 0.5)
		cout << poly.Calculate(i) << ' ';

	cout << endl << "Errors: " << endl;
	double avgErr = 0;
	for (double i = -10; i < 10; i += 0.5)
	{
		double err = Error(poly.Calculate(i), FUNC(i));
		cout << err << ' ';
		avgErr += err;
	}
	cout << endl << "Average error: " << avgErr / 20;
	system("pause");
	return 0;
}
