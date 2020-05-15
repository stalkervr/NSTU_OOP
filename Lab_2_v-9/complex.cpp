
#include "complex.h"
#include <iostream>

complex operator+(complex a1, complex a2)
{
	return complex(a1.re + a2.re, a1.im + a2.im);
}

complex operator-(complex a1, complex a2)
{
	return complex(a1.re - a2.re, a1.im - a2.im);
}

complex operator-(complex a1)
{
	return complex(-a1.re, a1.im);
}

complex operator*(complex a1, complex a2)
{
	return complex((a1.re * a2.re - a1.im * a2.im) + (a1.re * a2.im + a2.re * a1.im));
}

complex operator/(complex a1, complex a2)
{
	return complex(((a1.re * a2.re + a1.im * a2.im) + (a2.re * a1.im - a1.re * a2.im)) / ((a2.re * a2.re) + (a2.im * a2.im)));
}

void complex::print() 
{
	std::cout << re << " + " << im << "*i"<<std::endl;
}
