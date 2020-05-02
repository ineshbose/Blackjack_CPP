#ifndef CARD_H
#define CARD_H

class Card{
    
    private:
        int number; // Card Number
        char suit;  // Card Suit
        bool block; // Boolean value for Ace Switching

    public:
        // Default Constructor
        Card();
        // Parameterised Constructor (for initializing deck)
        Card(int no, char s);
        // Getter Functions    
        int getNumber();
        char getSuit();
        bool getBlock();
        // Setter Functions
        void setNumber(int no);
        void setSuit(char c);
        void setBlock(bool b);
        // Printing Card Details
        char getPrintNumber();
        void printCardL1();
        void printCardL2();
};

#endif