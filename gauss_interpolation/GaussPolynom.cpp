#include "GaussPolynom.h"

void printarr(double* arr, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

double GaussPolynom::Delta(int i, int pow)const
{
	return delta[pow][i];
}

double GaussPolynom::Q(double q, int m)
{
	double result = q;
	for (int i = 1; i < m; i++)
		result *= q - i;
	return result;
}

double GaussPolynom::Factorial(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	return n * Factorial(n - 1);
}

GaussPolynom::GaussPolynom(const InterpolationNodes& theX, const InterpolationNodes& y, int N) :x(N), n(N)
{
	delta = new InterpolationNodes[2 * N];
	for (int i = 0; i < 2 * N; i++)
		delta[i] = InterpolationNodes(N);
	for (int i = -N; i < N; i++) {
		x[i] = theX[i];
	}
	delta[0] = y;
	for (int pow = 1; pow < 2 * N; pow++){
		for (int i = -N; i < N; i++){
			delta[pow][i] = delta[pow - 1][i + 1] - delta[pow - 1][i];
		}
	}

	h = x[1] - x[0];
	//printarr(deltas, 2 * N + 1);
}

GaussPolynom::~GaussPolynom()
{
	delete[] delta;
}

double GaussPolynom::Calculate(double point)const
{
	double q = (point - x[0]) / h;
	double result = Delta(0, 0);
	int k = 1;
	for (int i = 1; i < n; i++) {
		result += (Q(q + i - 1, 2 * i - 1) / Factorial(2 * i - 1))*Delta(-(i - 1), 2 * i - 1);
		result += (Q(q + i - 1, 2 * i) / Factorial(2 * i))*Delta(-i, 2 * i);
	}
	return result;
}

GaussPolynom::GaussPolynom(const GaussPolynom& GP)
{
	h = GP.h;
	x = GP.x;
}
GaussPolynom& GaussPolynom::operator=(const GaussPolynom& GP)
{

}