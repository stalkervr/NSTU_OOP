#pragma once
#include "T_Complex.h"
#include "Complex.h"

class T_Complex : public Complex
{
    //char* t_number;

public:
    //T_Complex();
    T_Complex(double re, double im);
    //T_Complex(const T_Complex& object);

    ~T_Complex();

    /*char* getTnumber();
};*/
};
