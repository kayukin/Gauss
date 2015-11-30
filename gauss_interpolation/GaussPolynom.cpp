#include "GaussPolynom.h"

void printarr(double* arr, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

double GaussPolynom::Delta(const InterpolationNodes& y, int i, int pow)
{
	if (pow > 1)
		return Delta(y, i + 1, pow - 1) - Delta(y, i, pow - 1);
	return y[i + 1] - y[i];
}

double GaussPolynom::Q(double q, int m)
{
	for (int i = 1; i < m; i++)
		q *= q - i;
	return q;
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
	deltas = new double[2 * N + 1];
	for (int i = -N; i < N; i++) {
		x[i] = theX[i];
	}
	deltas[0] = y[0];
	int k = 1;
	for (int n = 1; n < N + 1; n++) {
		deltas[k++] = Delta(y, -(n - 1), 2 * n - 1);
		deltas[k++] = Delta(y, -n, 2 * n);
	}
	h = Delta(x, 0, 1);
	//printarr(deltas, 2 * N + 1);
}

GaussPolynom::~GaussPolynom()
{

}

double GaussPolynom::Calculate(double point)
{
	double q = (point - x[0]) / h;
	double result = deltas[0];
	int k = 1;
	for (int i = 1; i < n; i++) {
		result += (Q(q + i - 1, 2 * i - 1) / Factorial(2 * i - 1))*deltas[k++];
		result += (Q(q + i - 1, 2 * i) / Factorial(2 * i))*deltas[k++];
	}
	return result;
}
