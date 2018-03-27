#include <iostream>
#include <Vector.hpp>
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
const bool &Vector::operator== ( Vector &wektor) 
{
    return (this->sizeOfVector() == wektor.sizeOfVector());
}

void Test::testSetVector1Argument(void)
{
    Vector wektor;
    for (int i = 0; i < 1000; i++){
        wektor.setVector(i);
        if (wektor.vect.back() != (double)i)
            std:: cout << "Test oblany na:" << i << std::endl;
        }
        std::cout << "Zakoczono";
    }
    void Test::testSetVector2Argument(void)
{
    Vector wektor;
    wektor.setVector(0);
    for (int i = 0; i < 1000; i++){
        wektor.setVector(i,(double)i);
        if (wektor[i] != (double)i)
            std:: cout << "Test oblany na:" << i << std::endl;
        }
        for (int i = 0; i < 1000; i++){
            auto randomized = rand();
        wektor.setVector(randomized,randomized);
        if (wektor[randomized] != randomized)
            std:: cout << "Test oblany na:" << i << std::endl;
    }
        std::cout << "Zakoczono";
    }
void Test::testOperatorGet(void)
{
    for (int i = 0; i < 1000; i++){
            auto randomized = rand();
        wektor.setVector(randomized,randomized);
    }
    for (int i = 0; i < 1000; i++){
            auto randomized = rand();
        if (wektor[randomized] != wektor.getVector(randomized))
            std::cout << "Error"
    }
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
    Test test;
    test.testSetVector1Argument();
    test.testSetVector2Argument();
    test.testOperatorGet();
    return 0;
}
