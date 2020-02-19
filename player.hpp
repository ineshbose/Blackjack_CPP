#include <iostream>
#include <string.h>

class Player{

private:
    char name[100];
    vector<Card> hand;
    int sum, cash, bet;
    int wins, loses;

public:
    Player(){
        strcpy(name, "Unknown");
        sum = 0;
        bet = 0;
        cash = 1000;
        wins = 0;
        loses = 0;
    }

    Player(char pname[100]){
        strcpy(name, pname);
        sum = 0;
        bet = 0;
        cash = 1000;
        wins = 0;
        loses = 0;
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
    void incrementLoses(){
        loses+=1;
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
    cout<<endl;
    // │ ─ └ ┐ ┘ ┌
    for(int i=0;i<hand.size();i++){
        //cout<<" ┌───────┐ ";
        cout<<" +-------+ ";
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        cout<<" |       | ";
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        cout<<" |       | ";
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        hand[i].printCard();
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        cout<<" |       | ";
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        cout<<" |       | ";
    }
    cout<<endl;
    for(int i=0;i<hand.size();i++){
        //cout<<" └───────┘ ";
        cout<<" +-------+ ";
    }
    cout<<endl;
}