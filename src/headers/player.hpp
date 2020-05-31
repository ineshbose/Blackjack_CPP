#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "card.h"
#include <vector>
#include <string>

class Player{

private:
    std::string name;        // Name of Player
    std::vector<Card> hand;  // Player's Cards
    int sum, cash, bet;      // Cards' Sum, Player's Cash, Player's Bet
    int wins, loses;         // Player's Stats (number of wins and loses)

public:
    Player();
    std::string getName();
    int getBet();
    int getCash();
    int getSum();
    int getWins();
    int getLoses();
    void setName(std::string nm);
    void setBet(int b);
    void addCash(int c);
    void incrementWins();
    void incrementLoses();
    void switchAce();
    void addCard(Card C);
    void clearCards();
    void printCards();
};

#endif