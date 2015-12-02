#include "DArray.h"

DArray::DArray(int n) : size(n)
{
	x = new double[2 * size + 1];
}

DArray::DArray(const DArray & IN) : size(IN.size)
{
	x = new double[2 * size + 1];
	for (int i = 0; i < 2 * size + 1; i++) {
		x[i] = IN.x[i];
	}
}

DArray::DArray()
{
	x = new double[1];
}


DArray::~DArray()
{
	delete[] x;
}

DArray & DArray::operator=(const DArray &IN)
{
	if (&IN == this)
		return *this;
	delete[] x;
	size = IN.size;
	x = new double[2 * size + 1];
	for (int i = 0; i < 2 * size + 1; i++) {
		x[i] = IN.x[i];
	}
	return *this;
}

double & DArray::operator[](int i)
{
	return x[i + size];
}

double DArray::operator[](int i) const
{
	return x[i + size];
}

std::ostream& operator<<(std::ostream& os, const DArray& IN)
{
	for (int i = -IN.size; i <= IN.size; i++)
	{
		os << IN[i] << ' ';
	}
	return os;
}