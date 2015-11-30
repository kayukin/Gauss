#include <iostream>
#include <fstream>
#include "GaussPolynom.h"

using namespace std;

#define X0 0.5
#define STEP 0.5
#define N 5
#define FUNC abs


void GetInterpolationNodes(double(function(double)), double x0, double step, int n, InterpolationNodes &x, InterpolationNodes &y)
{
	InterpolationNodes X(n);
	InterpolationNodes Y(n);

	double current = x0 - step*n;
	for (int i = -n; i < n + 1; i++, current += step)
	{
		X[i] = current;
		Y[i] = function(current);
	}
	x = X;
	y = Y;
	cout << x << endl;
	cout << y << endl;
}
int main()
{
	InterpolationNodes x;
	InterpolationNodes y;
	GetInterpolationNodes(FUNC, X0, STEP, N, x, y);

	GaussPolynom poly(x, y, N);
	for (double xx = -10; xx < 10; xx += 0.5)
		cout<<poly.Calculate(xx)<<' ';
	//printarr(x, N);
	//printarr(y, N);

	system("pause");
	return 0;
}
