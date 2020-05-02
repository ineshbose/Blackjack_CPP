#include <vector>
#include "card.h"

class Deck{

    private:
        std::vector<Card> deck; // Deck (Vector) of Cards

    public:
        void initializeDeck();
        int getSize();
        Card deal();
};