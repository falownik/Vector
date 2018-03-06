#include <iostream>
#include <array>

class Vector{
private:

public:
int lenght, l;
//std::array<double, lenght> vector;
double *vector = new double[lenght];
Vector(double *v)
: vector(v){}
Vector(double [] value)
: vector(value[]){}
void setVector (double &);
double getVector (int x);
};
