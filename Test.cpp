#include "Vector.hpp"
#include "Test.hpp"

bool Test::testSetVector1Argument(void)
{
    Vector wektor;
    for (int i = 0; i < 1000; i++){
        wektor.setVector(i);
        if (wektor.vect.back() != (double)i)
            return false;
        }
        return true;
    }
    bool Test::testSetVector2Argument(void)
{
    Vector wektor;
    wektor.setVector(0);
    for (int i = 0; i < 1000; i++){
        wektor.setVector(i,(double)i);
        if (wektor[i] != (double)i)
            return false;
        }
        for (int i = 0; i < 1000; i++){
            auto randomized = rand();
        wektor.setVector(randomized,randomized);
        if (wektor[randomized] != randomized)
            return false;
        
            return true;
        }
}
bool Test::testOperatorGet(void)
{
    Vector wektor;
    for (int i = 0; i < 1000; i++){
            auto randomized = rand();
        wektor.setVector(randomized,randomized);
    }
    for (int i = 0; i < 1000; i++){
            auto randomized = rand();
        if (wektor[randomized] != wektor.getVector(randomized))
            return false;    
        }
        return true;
}
bool Test::testOperatorRead(void)
{
    Vector wektor;
    std::cin >> wektor;
}
bool Test::testOperatorEqualUnary(void)
{
    Vector wektor1({1,1,2});
    Vector wektor2({1,1,2});
    return wektor1 == wektor2;
}
