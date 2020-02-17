#include <iostream>
#include <stdlib.h>

class Card{

private:
    int number;
    char suit;

public:
    int getNumber()
    {
        return number;
    }

    void dealCard()
    {
        number = (rand() % 13) + 1;
    }
};