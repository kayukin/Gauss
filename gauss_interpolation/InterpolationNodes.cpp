#include "InterpolationNodes.h"



InterpolationNodes::InterpolationNodes(int n) : size(n)
{
	x = new double[2 * size + 1];
}

InterpolationNodes::InterpolationNodes(const InterpolationNodes & IN) : size(IN.size)
{
	x = new double[2 * size + 1];
	for (int i = 0; i < 2 * size + 1; i++) {
		x[i] = IN.x[i];
	}
}

InterpolationNodes::InterpolationNodes()
{
	x = new double[1];
}


InterpolationNodes::~InterpolationNodes()
{
	delete[] x;
}

InterpolationNodes & InterpolationNodes::operator=(const InterpolationNodes &IN)
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

double & InterpolationNodes::operator[](int i)
{
	return x[i + size];
}

double InterpolationNodes::operator[](int i) const
{
	return x[i + size];
}

std::ostream& operator<<(std::ostream& os, const InterpolationNodes& IN)
{
	for (int i = -IN.size; i <= IN.size; i++)
	{
		os << IN[i] << ' ';
	}
	return os;
}