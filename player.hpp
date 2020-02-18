#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Player{

private:
    char name[100];
    Card hand[10];
    int sum, cash, bet, index;
    int wins;
    bool win;

public:

    Player(char pname[100]){
        strcpy(name, pname);
        index = 0;
        sum = 0;
        bet = 0;
        cash = 1000;
        wins = 0;
        win = false;
    }
    
    char *getName(){
        return name;
    }

    int getBet(){
        return bet;
    }

    int getCash(){
        return cash;
    }

    int getSum(){
        return sum;
    }
    int getWins(){
        return wins;
    }
    void incrementWins(){
        wins+=1;
    }

    bool setBet(int b){
        if(b<=cash){
            cash-=b;
            bet+=b;
            return true;
        }
        else{
            cout<<"You don't have enough money!";
            return false;
        }
    }
    void setCash(int c){
        cash+=c;
    }
    void printCards();
    void addCard(Card c){
        hand[index] = c;
        if(c.getNumber()>10){
            c.setNumber(10);
        }
        sum+= c.getNumber();
        index++;
    }
};

void Player::printCards(){
    for(int i=0;hand[i].getSuit()!='\0';i++){
        hand[i].printCard();
    }
    cout<<endl;
}