#ifndef GAME_HPP
#define GAME_HPP

#include "deck.hpp"
#include "dealer.hpp"
#include "player.hpp"
#include "print.hpp"
#include "statistics.hpp"
#include <string>

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
        bool startBet();
        bool startGame();
        void beginGame();
        void beginMenu(bool rep, std::string message);
        void saveGame();
        void loadGame();
        void printStatistics();
        void printInstructions();
        void printTop();
        void printBody();
};

#endif