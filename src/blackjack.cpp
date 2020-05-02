#include "headers/blackjack.hpp"
#include <iostream>
#include <time.h>

int main(){

    srand(time(NULL));          // To seed rand() function across all files

    Game game;                  // Constructs object GAME
    game.beginMenu(false, "");  // Begins with the interface

    return 0;                   // Return integer value at end of main()

}