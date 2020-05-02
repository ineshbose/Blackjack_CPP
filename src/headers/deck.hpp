#ifndef DECK_HPP
#define DECK_HPP

#include "card.h"
#include <vector>

class Deck{

    private:
        std::vector<Card> deck; // Deck (Vector) of Cards

    public:
        void initializeDeck();
        int getSize();
        Card deal();
};

#endif