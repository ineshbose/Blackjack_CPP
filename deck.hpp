#include <iostream>
#include <vector>
//#include "card.hpp"

class Deck{
    private:
        vector<Card> deck;
    public:
        int getSize(){
            return deck.size();
        }
        void initializeDeck();
        void printDeck();
        Card deal();
};

void Deck::initializeDeck(){
    char suits[4] = {'S','H','D','C'};
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            Card c(j+1,suits[i]);
            //deck[13*i+j].setNumber(j+1);
            //deck[13*i+j].setSuit(suits[i]);
            deck.push_back(c);
        }
    }
}

void Deck::printDeck(){
    for(int i=0;i<deck.size();i++){
        cout<<deck[i].getNumber()<<" ";
    }
    cout<<endl;
}

Card Deck::deal(){
    int val = (rand()%(deck.size()));
    Card t = deck[val];
    deck.erase(deck.begin()+val);
    return t;
}