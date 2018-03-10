#include <iostream>
#include <Vector.hpp>
#include <vector>


void Vector::setVector(int x, double value){
    vect[x]  = value;
}
double Vector::getVector(int x){
    return vect[x];
}
int Vector::sizeOfVector(void){
    return vect.size();
}
// Definicja przeciążenia <<
 std::ostream& operator<<(std::ostream& os, Vector& wektor){
     for (auto b: wektor.vect)
        os << b;
    return os;
 }
int main(void){
    Vector wektor({1.1,2.1});
    Vector wektor1({1,2});
    wektor = wektor + wektor1;
    //std::cout << wektor.getVector(0);
    //std::cout << wektor.getVector(1);
    std::cout << wektor;
    //for (auto b: wektor.vect)
    //std::cout << wektor.vect;
    return 0;
}
