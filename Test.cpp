#include "Vector.hpp"
#include "Test.cpp"

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
void Test::testOperatorRead(void)
{
    Vector wektor;
    std::cin >> wektor;
    
    
}
