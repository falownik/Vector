#include <iostream>
#include <vector>

class Vector{
private:

public:
int lenght, l;
std::vector<double> vect;
Vector(){}
Vector(std::vector<double> v)
: vect(v){}
void setVector (int , double);
double getVector (int );
int sizeOfVector(void);
Vector operator+(Vector wektor2){
if (this->sizeOfVector()!=(wektor2).sizeOfVector()){
    std::cout << "blad sumowania wektorow" << std::endl;
}
Vector wynik;
for (int i = 0; i < this->sizeOfVector(); i++){
    this->setVector(i, this->getVector(i) + (wektor2).getVector(i));
}
return wynik;
}
//deklaracja przeciążenia operatora <<
friend std::ostream& operator<<(std::ostream&,Vector &);
//Destruktor
~Vector(){}
};
