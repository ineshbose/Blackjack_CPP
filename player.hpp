#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Player{

private:
    char name[100];
    Card cards[5];
    int sum, cash, bet, index;
    int win;

public:
    Player(char pname[100]){
        strcpy(name, pname);
        index = 0;
        sum = 0;
        bet = 0;
        cash = 5000;
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
    void printName(){
        cout << name;
    }
    bool addCard(){
        cards[index].dealCard();
        sum += cards[index].getNumber();
        index++;
        if (checkSum() == 2){
            cout << "\nYou got busted!";
            return false;
        }
        else if (checkSum() == 3){
            cout << "\nBlackjack!";
        }
        return true;
    }
    int getSum(){
        return sum;
    }
};