#include <iostream>
#include "Vector.hpp"
#include "Test.hpp"
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <exception>

using namespace std;

void Vector::setVector(int x, double value){
    while (vect.size() <= x)
        vect.push_back(0);
    vect[x]  = value;
}
void Vector::setVector(double x){
    vect.push_back(x);
}
double Vector::getVector(int x){
    return vect[x];
}
int Vector::sizeOfVector(void){
    return vect.size();
}

bool eq(Vector wektor1, Vector wektor2)
{
    return wektor1.sizeOfVector() == wektor2.sizeOfVector();
}
Vector operator+(Vector wektor1, Vector wektor2)
{
    if (!eq(wektor1, wektor2))
        ;//wstawić procedurę
    Vector wynik;
    for ( int i = 0 ; i < wektor1.sizeOfVector() ; i++ )
        wynik.setVector(wektor1[i] + wektor2[i]);
        //std::cout << wynik;
    return wynik;
}
Vector &Vector::operator+=(Vector &wektor2)
{
    if (!eq(*this, wektor2))
        ;//wstawić procedurę
    for ( int i = 0 ; i < this->sizeOfVector() ; i++ )
        this->setVector(i, this->getVector(i) + wektor2.getVector(i) );
    return *this;
}
Vector operator-(Vector wektor1, Vector wektor2)
{
    if (!eq(wektor1, wektor2))
        ;//wstawić procedurę
    Vector wynik;
    for ( int i = 0 ; i < wektor1.sizeOfVector() ; i++ )
        wynik.setVector(wektor1[i] - wektor2[i]);
        //std::cout << wynik;
    return wynik;
}
Vector &Vector::operator-=(Vector &wektor2)
{
    if (!eq(*this, wektor2))
        ;//wstawić procedurę
    for ( int i = 0 ; i < this->sizeOfVector() ; i++ )
        this->setVector(i, this->getVector(i) - wektor2.getVector(i) );
    return *this;
}
Vector operator*(Vector wektor1, Vector wektor2)
{
    if (!eq(wektor1, wektor2))
        ;//wstawić procedurę
    Vector wynik;
    for ( int i = 0 ; i < wektor1.sizeOfVector() ; i++ )
        wynik.setVector(wektor1[i] * wektor2[i]);
        //std::cout << wynik;
    return wynik;
}
Vector &Vector::operator*=(Vector &wektor2)
{
    if (!eq(*this, wektor2))
        ;//wstawić procedurę
    for ( int i = 0 ; i < this->sizeOfVector() ; i++ )
        this->setVector(i, this->getVector(i) * wektor2.getVector(i) );
    return *this;
}

 std::ostream &operator<<(std::ostream& os, const Vector &wektor)
 {
     for (auto b: wektor.vect)
        os << b << " ";
    os << std::endl;
    return os;
}

void operator>>(std::istream &is, Vector &wektor)
{
    double temp = 0.0;
    string buff;
    getline(is, buff);
    stringstream buffer(buff);

    do
    {
            buffer >> temp;
            wektor.setVector(temp);
        }while (!buffer.fail());
        wektor.vect.pop_back();
    
}
const bool Vector::operator== ( Vector &wektor) 
{
    bool check = true;
    if (!(this->sizeOfVector() == wektor.sizeOfVector())) return false;
    auto x = 0;
    while (x < this->sizeOfVector())
    {
    check = (vect.at(x) == wektor[x]);
    if (check == false) return false;
    x++;
    }
    return true;
}

const bool Vector::operator!= ( Vector &wektor) 
{
    bool check (true);
    if (!(this->sizeOfVector() != wektor.sizeOfVector())) return false;
    auto x = 0;
    while (x < this->sizeOfVector())
    {
    check = (vect.at(x) != wektor[x]);
    if (check == false) return false;
    }
    return true;
}


int main(void){
    //Vector wektor;
    //std::cin >> wektor;
    //std::cout << wektor.getVector(0);
    //std::cout << wektor.getVector(1);
    //std::cout <<wektor;
    //std::cout << wektor.sizeOfVector() << wektor1.sizeOfVector();
    //for (auto b: wektor.vect)
    //std::cout << wektor.vect;
    Vector wektor ({1,2,1});
    Vector wektor1 ({1,2});
    if (wektor == wektor1)
    std::cout << "tak";
    Test test;
    std::cout << test.testSetVector1Argument();
    std::cout << test.testSetVector2Argument();
    std::cout << test.testOperatorGet();
    std::cout << test.testOperatorEqualUnary();
    std::cout << test.testOperatorUnequalUnary();
    std::cout << test.testOperatorPlus();
    std::cout << test.testOperatorPlusUnary();
    std::cout << test.testOperatorMinus();
    std::cout << test.testOperatorMinusUnary();
    std::cout << test.testOperatorMultiplication();
    std::cout << test.testOperatorMultiplicationUnary();
    return 0;
}
