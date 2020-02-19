#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>

using namespace std;

class Player{

private:
    char name[100];
    vector<Card> hand;
    int sum, cash, bet;
    int wins;

public:

    Player(char pname[100]){
        strcpy(name, pname);
        sum = 0;
        bet = 0;
        cash = 1000;
        wins = 0;
    }

    Player(const Player &p){
        strcpy(name,p.name);
        sum = 0;
        bet = 0;
        cash = p.cash;
        wins = p.wins;
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
            bet=b;
            return true;
        }
        else{
            //cout<<"You don't have enough money!";
            return false;
        }
    }
    void setCash(int c){
        cash+=c;
    }
    void addCard(Card c){
        hand.push_back(c);
        if(c.getNumber()>10){
            c.setNumber(10);
        }
        sum+= c.getNumber();
    }
    void clearCards(){
        hand.clear();
        sum=0;
    }
    void printCards();
};

void Player::printCards(){
    for(int i=0;i<hand.size();i++){
        hand[i].printCard();
    }
    cout<<endl;
}