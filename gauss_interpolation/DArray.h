#pragma once
#include <iostream>

class DArray
{
	double* x;
	int size;
public:
	DArray(int n);
	DArray(const DArray&);
	DArray();
	~DArray();
	DArray& operator=(const DArray&);
	double& operator[](int i);
	double operator[](int i)const;
	friend std::ostream& operator<<(std::ostream& os, const DArray& IN);
	int GetSize()const{ return size; }
};

