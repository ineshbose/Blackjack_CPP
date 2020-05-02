#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include "player.hpp"
#include "color.hpp"
#include <string>

class PlayerSet{

    private:
        std::string name;             // Name of Player
        int cash, wins, loses;   // Stat Data
        // This class is almost similar to Player, but does not need vectors and betting values.

    public:
        PlayerSet();
        std::string getName();
        int getCash();
        int getWins();
        int getLoses();
        void setValues(std::string nm, int c, int w, int l);

};

class Statistics{

    private:
        PlayerSet p[3];                 // 3 Players

    public:
        Statistics();
        bool check(Player pl);
        void print();
        void saveStats();
        void loadStats();

};

#endif