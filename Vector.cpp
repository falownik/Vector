#include <iostream>
#include <Vector.hpp>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

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
/*void operator>>(std::istream &is, Vector &wektor){
    int i = 0;
    string bufor = "";
    double wartosc = 0.0;
    int czy_wczytana = 0;
    do
    {
        czy_wczytana = fscanf(stdin, "%d", wartosc);
        wektor.setVector(wartosc);
        i++;
    }while (czy_wczytana == 1);
}
*/
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
}
const bool &Vector::operator== ( Vector &wektor) 
{
    return (this->sizeOfVector() == wektor.sizeOfVector());
}






int main(void){
    Vector wektor;
    std::cin >> wektor;
    //std::cout << wektor.getVector(0);
    //std::cout << wektor.getVector(1);
    std::cout <<wektor;
    //std::cout << wektor.sizeOfVector() << wektor1.sizeOfVector();
    //for (auto b: wektor.vect)
    //std::cout << wektor.vect;
    return 0;
}
