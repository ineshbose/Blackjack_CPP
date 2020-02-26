#include <iostream>
#include <time.h>
#include "headers/game.hpp"

using namespace std;


int main(){

    srand(time(NULL));  // To seed rand() function across all files

    Game game;          // Constructs object GAME
    game.beginMenu(false, "");  // Begins with the interface

    return 0;           // Return integer value at end of main()

}

// BLACKJACK C++ developed by Inesh Bose (https://inesh.xyz/)