#include <iostream>
#include <Vector.hpp>
#include <array>


void Vector::setVector(double &value){
    vector[x]  = *value;
}
double Vector::getVector(int x){
    return vector[x];
}

int main(void){
    Vector wektor = (1.1, 1.1, 2.2);
    std::cout << wektor.getVector(0);
}
