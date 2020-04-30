class Deck{

    private:
        vector<Card> deck; // Deck (Vector) of Cards

    public:
        void initializeDeck();
        int getSize();
        Card deal();
};