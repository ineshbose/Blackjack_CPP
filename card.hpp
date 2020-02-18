#include <iostream>
#include <stdlib.h>

using namespace std;

class Card{

private:
    int number;
    char ace;

public:
    void setNumber(int no){
        number = no;
    }
    int getNumber(){
        return number;
    }

    void dealCard(){
        int val = (rand() % 13) + 1;
        switch(val){
            //case 1: ace='A'; break;
            case 11:
            case 12:
            case 13: number=10; break;
            default: number = val;
        }
    }

    void aceSwitch(bool up){
        if(up){
            number=11;
        }
        else{
            number=1;
        }
    }
};
/*
class Deck{
    private: Card cards[52];
    public:
            Deck();
            void getCard();
};

Deck::Deck(){
    for(int i=1;i<=13;i++){
        for(int j=0;j<4;j++){
            cards[j*i+j].setNumber(i);
            cout<<cards[j*i+j].getNumber()<<"\n";
        }
    }
}*/