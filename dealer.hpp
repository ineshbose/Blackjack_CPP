#include <iostream>
#include <stdlib.h>

using namespace std;

class Dealer{

private:
    Card hand[10];
    int sum, index;
    bool win;

public:
    Dealer(){
        index = 0;
        sum = 0;
        win = false;
    }
    int getSum(){
        return sum;
    }
    void addCard(Card c){
        if (c.getNumber() > 10){
            c.setNumber(10);
        }
        hand[index]=c;
        sum+=c.getNumber();
        index++;
    }
};