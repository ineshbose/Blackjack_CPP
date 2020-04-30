class Game{

    private:
        Player player;   // Player in the game (user)
        Dealer dealer;   // Dealer in the game
        Deck deck;       // Deck of cards in the game
        Statistics s;    // Leaderboard

    public:
        Game();
        bool dealDealer();
        char compareSum();
        bool checkWins();
        char checkEnd();
        void startBet();
        int startGame();
        void beginGame();
        void beginMenu(bool rep, string message);
        void saveGame();
        void loadGame();
        void printStatistics();
        void printInstructions();
        void printTop();
        void printBody();
};