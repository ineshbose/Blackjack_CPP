#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Dealer{

private:
    vector<Card> hand;
    int sum;

public:
    Dealer(){
        sum = 0;
    }
    int getSum(){
        return sum;
    }
    void addCard(Card c){
        hand.push_back(c);
        if (c.getNumber() > 10){
            c.setNumber(10);
        }
        sum += c.getNumber();
    }
    void clearCards(){
        hand.clear();
        sum = 0;
    }
    void printCards();
};

void Dealer::printCards(){
    for(int i=0;i<hand.size();i++){
        hand[i].printCard();
    }
    cout<<endl;
}