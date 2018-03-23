#include <iostream>
#include <Vector.hpp>
#include <vector>


void Vector::setVector(int x, double value){
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
void operator>>(std::istream &is, Vector &wektor){
    std::string buffer = "";
    double number = 0.0;
    int i = 0;

    do
    {
        is >> buffer;
        buffer >> number;
        wektor[i] = number;
        i++;

    }while (buffer != '\n');

}





int main(void){
    Vector wektor({1.1,2.1});
    Vector wektor1({1,2});
    wektor += wektor1;
    std::cin >> wektor;
    //std::cout << wektor.getVector(0);
    //std::cout << wektor.getVector(1);
    std::cout <<wektor * wektor1;
    //std::cout << wektor.sizeOfVector() << wektor1.sizeOfVector();
    //for (auto b: wektor.vect)
    //std::cout << wektor.vect;
    return 0;
}
