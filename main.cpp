#include <fstream>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include "card.hpp"
#include "dealer.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "game.hpp"
#include "print.hpp"
#include "color.hpp"

using namespace std;

void clrscr(){
    system("cls");
}

int main(){

    clrscr();
    srand(time(NULL));
    char name[100] = "Inesh";
    Player player(name);
    Dealer dealer;
    Deck deck;
    deck.initializeDeck();
    Game game(player, dealer, deck);
    char choice = 'Y';
    while(choice=='Y' || choice=='y'){
        clrscr();
        cout<<Print::title_blackjack<<endl;
        game.beginGame();
        cout<<"\nContinue game? ";
        cin>>choice;
    }
    //saveGame(player);*/
    return 0;
}