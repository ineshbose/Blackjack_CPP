#include <iostream>
#include <stdlib.h>

using namespace std;

class Dealer{

private:
    Card cards[5];
    int sum, index, win;

public:
    Dealer(){
        index = 0;
        sum = 0;
        win = 0;
    }
    int checkSum(){
        if (sum > 21)
        {
            win = 2;
        }
        if (sum == 21)
        {
            win = 3;
        }
        return win;
    }
    bool addCard(){
        cards[index].dealCard();
        sum += cards[index].getNumber();
        index++;
        if (checkSum() == 2)
        {
            cout << "\nDealer got busted (" << getSum() << ")\n";
            return false;
        }
        else if (checkSum() == 3)
        {
            cout << "\nBlackjack!";
            return false;
        }
        return true;
    }
    int getSum(){
        return sum;
    }
};