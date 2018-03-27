#include <iostream>
#include <vector>

//klasa Vector
class Vector
{
private:
public:
    std::vector<double> vect;
    Vector() {}
    Vector(std::vector<double> v)
        : vect(v) {}
    Vector (double x){vect.push_back(x);}
    Vector(const Vector &wektor)
        : vect(wektor.vect) {}
    void setVector(int, double);
    void setVector(double);
    double getVector(int);
    int sizeOfVector(void);


    //przeciazanie + i +=
    friend Vector operator+(Vector, Vector);
    Vector &operator+=(Vector &);

        //przeciazanie - i -=
    friend Vector operator-(Vector, Vector);
    Vector &operator-=(Vector &);


    double &operator[](int x) { return vect[x]; };

    //przeciazanie >> i <<
    friend std::ostream &operator<<(std::ostream &, const Vector &);
    friend void operator>>(std::istream &, Vector &);

    //przeciazanie * i *=
    friend Vector operator*(Vector, Vector);
    Vector &operator*=(Vector &);

    //przeciazanie == i !=
    const bool operator== ( Vector &);
    const bool operator!= ( Vector &);

    //Destruktor
    ~Vector() {}
};

//pomocnicza funkcja porownojaca dlugosci wektorow
bool eq(Vector , Vector);
