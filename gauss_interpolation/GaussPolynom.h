#pragma once
#include<iostream>
#include"InterpolationNodes.h"

class GaussPolynom
{
	InterpolationNodes x;
	double* deltas;
	double h;
	int n;
	double Delta(const InterpolationNodes& y, int i, int pow);
	double Q(double q, int m);
	double Factorial(int n);
public:
	GaussPolynom(const InterpolationNodes& x, const InterpolationNodes& y, int n);
	~GaussPolynom();
	double Calculate(double point);
};

