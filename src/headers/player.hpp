#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "human.hpp"
#include <string>

class Player: public Human{

private:
    std::string name;        // Name of Player
    int cash, bet;           // Player's Cash, Player's Bet
    int wins, loses;         // Player's Stats (number of wins and loses)

public:
    Player();
    std::string getName();
    int getBet();
    int getCash();
    int getWins();
    int getLoses();
    void setName(std::string nm);
    void setBet(int b);
    void addCash(int c);
    void incrementWins();
    void incrementLoses();
    void clearCards();
};

#endif