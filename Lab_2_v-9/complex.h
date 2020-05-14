#pragma once
class complex
{
	double re;
	double im;

public:
	complex(double r, double i) { re = r; im = i; };
	complex(double r) { re = r; im = 0; };
	complex() { re = im = 0; };

	friend complex operator+ (complex, complex);
	friend complex operator- (complex, complex);
	friend complex operator- (complex);
	friend complex operator* (complex, complex);
	friend complex operator/ (complex, complex);
};

