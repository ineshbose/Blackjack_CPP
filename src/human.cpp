#include "headers/human.hpp"
#include <iostream>

// Default Constructor
Human::Human(){
    sum = 0;
}

// Getter Function for sum to check end of game
int Human::getSum(){
    switchAce();
    return sum;
}

// Switches Ace between 1 and 11
void Human::switchAce(){
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

// Adds card to Human's hand
void Human::addCard(Card c){
    hand.push_back(c);
    if(c.getNumber()>10){
        c.setNumber(10);
    }
    else if (c.getNumber()==1){
        c.setNumber(11);
    }
    sum+= c.getNumber();
}

// Clears Human's hand
void Human::clearCards(){
    hand.clear();
    sum = 0;
}

// Prints Human's cards
void Human::printCards(){
    std::cout<<"\n";
    for(int i=0;i<6;i++){
        for(int j=0;j<hand.size();j++){
            switch(i){
                case 0: std::cout<<".------."; break;
                case 1: std::cout<<"|"<<hand[j].getPrintNumber()<<".--. |"; break;
                case 2: hand[j].printCardL1(); break;
                case 3: hand[j].printCardL2(); break;
                case 4: std::cout<<"| '--'"<<hand[j].getPrintNumber()<<"|"; break;
                case 5: std::cout<<"`------'";
            }
        }
        std::cout<<"\n";
    }
}