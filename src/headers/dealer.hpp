class Dealer{
    
    private:
        vector<Card> hand; // Dealer's Cards
        int sum;           // Cards' Sum

    public:
        Dealer();
        int getSum();
        void switchAce();
        void addCard(Card c);
        void printFirstCard();
        void clearCards();
        void printCards();
};