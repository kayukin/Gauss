#pragma once
#include <iostream>

class InterpolationNodes
{
	double* x;
	int size;
public:
	InterpolationNodes(int n);
	InterpolationNodes(const InterpolationNodes&);
	InterpolationNodes();
	~InterpolationNodes();
	InterpolationNodes& operator=(const InterpolationNodes&);
	double& operator[](int i);
	double operator[](int i)const;
	friend std::ostream& operator<<(std::ostream& os, const InterpolationNodes& IN);
};

