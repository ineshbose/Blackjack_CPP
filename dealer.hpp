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
    void addCard(Card c);
    void clearCards(){
        hand.clear();
        sum = 0;
    }
    void printFirstCard(){
        cout<<endl;
        hand[0].printCard();
        cout<<endl;
    }
    void printCards();
    //void switchAce();
};

void Dealer::addCard(Card c){
    hand.push_back(c);
    if(c.getNumber()>10){
        c.setNumber(10);
    }
    /*   Brain Storming Required Here for 'A'
    else if (c.getNumber()==1){
        if((sum+11)<21){
            c.setNumber(11);
        }
        else{
            int s=0;
            for(int i=0;i<hand.size();i++){
                s+=hand[i].getNumber();
                if(hand[i].getNumber()==1 && s<sum){
                    sum-=10;
                }
            }
        }
    }*/
    else if (c.getNumber()==1){
        c.setNumber(11);
    }/*
    if(sum+c.getNumber()>21){
        for(int i=0;i<hand.size();i++){
            if(hand[i].getNumber()==1){
                sum-=10;
            }
        }
    }*/
    sum+= c.getNumber();
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