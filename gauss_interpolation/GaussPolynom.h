#pragma once
#include<iostream>
#include"DArray.h"

class GaussPolynom
{
	DArray x;
	DArray* delta;
	double h;
	int n;
	double Delta(int i, int pow)const;
	static double Q(double q, int m);
	static double Factorial(int n);
	void Copy(const GaussPolynom& GP);
public:
	GaussPolynom(const DArray& x, const DArray& y, int n);
	GaussPolynom(const GaussPolynom& GP);
	GaussPolynom& operator=(const GaussPolynom& GP);
	~GaussPolynom();
	double Calculate(double point)const;
};

