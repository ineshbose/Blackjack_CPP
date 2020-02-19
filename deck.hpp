#include <iostream>
#include <algorithm>
#include <vector>

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
    deck.clear();
    char suits[4] = {'S','H','D','C'};
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            Card c(j+1,suits[i]);
            deck.push_back(c);
        }
    }
    random_shuffle(deck.begin(), deck.end());
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