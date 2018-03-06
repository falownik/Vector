#include <iostream>
#include <Vector.hpp>
#include <vector>


void Vector::setVector(int x, double value){
    vect[x]  = value;
}
double Vector::getVector(int x){
    return vect[x];
}
int main(void){
    Vector wektor({1.1,2.1});
    std::cout << wektor.getVector(1);
}
