class Player{

private:
    string name;        // Name of Player
    vector<Card> hand;  // Player's Cards
    int sum, cash, bet; // Cards' Sum, Player's Cash, Player's Bet
    int wins, loses;    // Player's Stats (number of wins and loses)

public:
    Player();
    string getName();
    int getBet();
    int getCash();
    int getSum();
    int getWins();
    int getLoses();
    void setName(string nm);
    bool setBet(int b);
    void addCash(int c);
    void incrementWins();
    void incrementLoses();
    void switchAce();
    void addCard(Card C);
    void clearCards();
    void printCards();
};