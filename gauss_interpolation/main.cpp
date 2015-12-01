#include <iostream>
#include <fstream>
#include "GaussPolynom.h"

using namespace std;

#define X0 0.5
#define STEP 2.5
#define N 30
#define FUNC abs


void GetInterpolationNodes(double(function(double)), double x0, double step, int n, InterpolationNodes &x, InterpolationNodes &y)
{
	x = InterpolationNodes(n);
	y = InterpolationNodes(n);

	double current = x0 - step*n;
	for (int i = -n; i < n + 1; i++, current += step)
	{
		x[i] = current;
		y[i] = function(current);
	}
}

double AverageError(const InterpolationNodes& x, const InterpolationNodes& y, const GaussPolynom& polynom)
{
	double res = 0;
	for (int i = -x.GetSize(); i < x.GetSize(); i++){
		res += abs(polynom.Calculate(x[i]) - y[i]);
	}
	res /= x.GetSize() * 2;
	return res;
}

int main()
{
	InterpolationNodes x;
	InterpolationNodes y;
	GetInterpolationNodes(FUNC, X0, STEP, N, x, y);

	GaussPolynom poly(x, y, N);
	cout << endl;
	cout << AverageError(x, y, poly);


	system("pause");
	return 0;
}
