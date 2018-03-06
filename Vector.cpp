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
Vector operator+(Vector wektor1, Vector wektor2){
if (wektor1.sizeOfVector()!=wektor2.sizeOfVector()){
    std::cout << "blad sumowania wektorow" << std::endl;
}
Vector wynik;
for (int i = 0; i < wektor1.sizeOfVector(); i++){
    wynik = wektor1 + wektor2;
}
return wynik;
}
int main(void){
    Vector wektor({1.1,2.1});
    std::cout << wektor.getVector(1);
}
