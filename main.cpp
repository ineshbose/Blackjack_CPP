#include <fstream>
#include <iostream>
#include <conio.h>
#include <algorithm>
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
//#include "print.hpp"
//#include "color.hpp"

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
    deck.printDeck();
    Game game(player, dealer, deck);
    char choice = 'Y';
    //while(choice!='N' && choice!='n'){
        //cout<<yellow<<Print::title_blackjack<<def<<endl;
        game.beginMenu(false, "");
        //cout<<"\nContinue game? ";
        //cin>>choice;
    //}
    //saveGame(player);*/
    return 0;
}