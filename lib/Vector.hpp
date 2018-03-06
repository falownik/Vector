#include <iostream>
#include <vector>

class Vector{
private:

public:
int lenght, l;
//std::array<double, lenght> vector;
std::vector<double> vect;
Vector(std::vector<double> v)
: vect(v){}
void setVector (int , double);
double getVector (int );
};
