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
        switchAce();
        return sum;
    }
    void clearCards(){
        hand.clear();
        sum = 0;
    }
    void printFirstCard();
    void addCard(Card c);
    void printCards();
    void switchAce();
};

void Dealer::addCard(Card c){
    hand.push_back(c);
    if(c.getNumber()>10){
        c.setNumber(10);
    }
    else if (c.getNumber()==1){
        c.setNumber(11);
    }
    sum+= c.getNumber();
}

void Dealer::printFirstCard(){
    cout<<endl;
    // │ ─ └ ┐ ┘ ┌
    for(int i=0;i<2;i++){
        //cout<<" ┌───────┐ ";
        cout<<" +-------+ ";
    }
    cout<<endl;
    for(int i=0;i<2;i++){
        cout<<" |       | ";
    }
    cout<<endl;
    for(int i=0;i<2;i++){
        cout<<" |       | ";
    }
    cout<<endl;
    hand[0].printCard();
    cout<<" |  / /  | ";
    cout<<endl;
    for(int i=0;i<2;i++){
        cout<<" |       | ";
    }
    cout<<endl;
    for(int i=0;i<2;i++){
        cout<<" |       | ";
    }
    cout<<endl;
    for(int i=0;i<2;i++){
        //cout<<" └───────┘ ";
        cout<<" +-------+ ";
    }
    cout<<endl;
    /*
    cout<<"\n +-------+ \n |       | \n |       | \n";
    hand[0].printCard();
    cout<<"\n |       | \n |       | \n +-------+ ";*/
}

void Dealer::printCards(){
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

void Dealer::switchAce(){
    if(sum>21){
        for(int i=0;i<hand.size();i++){
                if(hand[i].getNumber()==1 && !(hand[i].getBlock())){
                    hand[i].setBlock(true);
                    sum-=10;
                    return;
                }
        }
    }
}