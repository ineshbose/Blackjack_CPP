#ifndef PRINT_HPP
#define PRINT_HPP

#include <string>

struct Print{

    static std::string title_blackjack();
    static std::string begin_menu();
    static std::string statistics();
    static std::string instructions();
    static std::string bust();
    static std::string blackjack();
    static std::string dealer_wins();
    static std::string you_win();
    static std::string draw();
    static std::string dealer_border();
    static std::string player_border();

};

#endif