#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "card.h"
#include <vector>

class Human{

    protected:
        std::vector<Card> hand;
        int sum;

    public:
        Human();
        int getSum();
        void switchAce();
        void addCard(Card c);
        void clearCards();
        void printCards();
};

#endif