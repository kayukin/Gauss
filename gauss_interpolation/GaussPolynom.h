#pragma once
#include<iostream>
#include"InterpolationNodes.h"

class GaussPolynom
{
	InterpolationNodes x;
	InterpolationNodes* delta;
	double h;
	int n;
	double Delta(int i, int pow)const;
	static double Q(double q, int m);
	static double Factorial(int n);
public:
	GaussPolynom(const InterpolationNodes& x, const InterpolationNodes& y, int n);
	GaussPolynom(const GaussPolynom& GP);
	GaussPolynom& operator=(const GaussPolynom& GP);
	~GaussPolynom();
	double Calculate(double point)const;
};

