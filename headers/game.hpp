#include <vector>
#include <fstream>
#include "print.hpp"
#include "color.hpp"
#include "card.hpp"
#include "dealer.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "compatible.hpp"

using namespace std;

class Game{

    private:
        Player player;   // Player in the game (user)
        Dealer dealer;   // Dealer in the game
        Deck deck;       // Deck of cards in the game

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
        void printInstructions();
        void printTop();
        void printBody();
};


//////////////* Default Constructor *////

Game::Game(){
    deck.initializeDeck();
}

//////////////* Deals dealer towards the end *////

bool Game::dealDealer(){
    if(dealer.getSum()<player.getSum()){
        while (dealer.getSum() < 18){
            dealer.addCard(deck.deal());
            if (checkWins()){
                return false;
            }
        }
        return true;
    }
    else{
        if(checkWins()){
            return false;
        }
        return true;
    }
}

//////////////* Checkers *////

char Game::compareSum(){
    if(player.getSum()>dealer.getSum()){
        printTop();
        cout<<lightYellow<<Print::you_win<<def<<"\n    (Dealer has "<<dealer.getSum()<<")";
        return 'p';
    }
    else if(dealer.getSum()>player.getSum()){
        printTop();
        cout<<lightRed<<Print::dealer_wins<<def<<"\n    ("<<dealer.getSum()<<")";
        return 'd';
    }
    else{
        printTop();
        cout<<lightMagenta<<Print::draw<<def;
        return 'n';
    }
}

bool Game::checkWins(){
    switch(checkEnd()){
        case 'f': return false;
        case 'd': player.incrementLoses(); return true;
        case 'p': player.incrementWins();
                  player.addCash((player.getBet()*2));
                  return true;
    }
    return false;
}

char Game::checkEnd(){
    if(dealer.getSum()>21 || player.getSum()>21){
        printTop();
        cout<<red<<Print::bust<<def<<"\n    [Dealer : "<<dealer.getSum()<<" | "<<player.getName()<<" : "<<player.getSum()<<"]";
        if(dealer.getSum()>21){
            return 'p';
        }
        else if(player.getSum()>21){
            return 'd';
        }
    }
    else if(dealer.getSum()==21 || player.getSum()==21){
        printTop();
        cout<<lightGreen<<Print::blackjack<<def<<"\n    [Dealer : "<<dealer.getSum()<<" | "<<player.getName()<<" : "<<player.getSum()<<"]";
        if(dealer.getSum()==21){
            return 'd';
        }
        else if(player.getSum()==21){
            return 'p';
        }
    }
    return 'f';
}

//////////////* Game Starters *////

void Game::startBet(){
    int b;
    cout<< "Place your bet!\n\t"<<red<<"5\t"<<green<<"25\t"<<blue<<"50\t"<<magenta<<"100\t\n"<<def;
    cin>>b;
    if(player.getCash()>b){
        switch(b){
            case 5:
            case 25:
            case 50:
            case 100: player.setBet(b); break;
            default: cout<<red<<"Invalid amount.\n"<<def; startBet();
        }
    }
    else{
        cout<<red<<"Insufficient funds.\n"<<def;
        startBet();
    }
}

int Game::startGame(){
    player.addCard(deck.deal());
    dealer.addCard(deck.deal());
    player.addCard(deck.deal());
    dealer.addCard(deck.deal());
    printBody();
    if(checkWins()){
        return 0;
    }
    char choice;
    cout << lightYellow << "\n\nHit or Stand? [H/S]: "<<def;
    cin>>choice;
    while(choice=='H' || choice=='h'){
        player.addCard(deck.deal());
        printBody();
        if (checkWins()){
            return 0;
        }
        cout << lightYellow << "\n\nHit or Stand? [H/S]: "<<def;
        cin >> choice;
    }
    return 1;
}

void Game::beginGame(){
    char cont = 'Y';
    while(cont!='N' && cont!='n'){
        if(deck.getSize()<36){
                deck.initializeDeck();
        }
        printTop();
        player.clearCards();
        dealer.clearCards();
        startBet();
        if (startGame() == 1){
            if (dealDealer()){
                switch (compareSum()){
                case 'p': player.incrementWins(); 
                          player.addCash((player.getBet()*2));
                          break;
                case 'd': player.incrementLoses(); break;
                case 'n': player.addCash(player.getBet()); break;
                }
            }
        }
        cout<<lightRed<<Print::dealer_border<<def;
        dealer.printCards();
        cout<<lightCyan<<Print::player_border<<def;
        player.printCards();
        cout << yellow << "\nYour wins: " << player.getWins()<< lightRed <<"\nYour loses: "<<player.getLoses()<<def<<"\n";
        cout<<"\nContinue playing? [Y/N]: ";
        cin>>cont;
    }
    char saveChoice;
    cout<<"\nSave game? [Y/N]: ";
    cin>>saveChoice;
    if(saveChoice == 'Y' || saveChoice == 'y'){
        saveGame();
    }
}

//////////////* Main Method to be Called *////

void Game::beginMenu(bool rep, string message){
    clearscr();
    cout<<yellow<<Print::title_blackjack<<def<<"\n";
    cout<<Print::begin_menu<<"\n";
    if(rep){
        cout<<red<<message<<def<<"\n";
    }
    int c;
    cout<<"Input : ";
    cin>>c;
    switch(c){
        case 1: char nm[100];
                cout<<"Enter player name: ";
                cin>>nm;
                player.setName(nm);
                beginGame();
                break;
        case 2: loadGame();
                beginGame();
                break;
        case 3: printInstructions();
                beginMenu(false, "");
                break;
        case 4: exit(0);
                break;
        default: beginMenu(true, "Invalid input.");
    }
}

//////////////* Data File Handling *////

void Game::saveGame(){
    fstream f1,f2;
    string filename;
    string path = "data/";
    cout<<"Enter filename: ";
    cin>>filename;
    path+=filename+".bin";
    string sName = player.getName();
    int sCash = player.getCash();
    int sWins = player.getWins();
    int sLoses = player.getLoses();
    int nameSize = sName.size();
    f2.open(path, ios::in | ios::binary);
    if(!f2.fail()){
        char choice;
        cout<<red<<"File already exists."<<def<<" Do you want to overwrite it? [Y/N]: ";
        cin>>choice;
        if(choice == 'N' || choice == 'n'){
            saveGame();
        }
    }
    f2.close();
    f1.open(path, ios::out | ios::binary);
    f1.write((char*)&nameSize, sizeof(nameSize));
    f1.write(sName.c_str(), sName.size());
    f1.write((char*)&sCash, sizeof(sCash));
    f1.write((char*)&sWins, sizeof(sWins));
    f1.write((char*)&sLoses, sizeof(sLoses));
    f1.close();
}

void Game::loadGame(){
    fstream f1;
    Player dummy;
    string filename;
    string path = "data/";
    cout<<"Enter filename: ";
    cin>>filename;
    path+=filename+".bin";
    f1.open(path, ios::in | ios::binary);
    if(!f1.fail()){
        string sName;
        int sCash;
        int sWins;
        int sLoses;
        int nameSize;
        f1.read((char*)&nameSize, sizeof(nameSize));
        sName.resize(nameSize);
        f1.read(&sName[0], sName.size());
        f1.read((char*)&sCash, sizeof(sCash));
        f1.read((char*)&sWins, sizeof(sWins));
        f1.read((char*)&sLoses, sizeof(sLoses));
        f1.close();
        player.setName(sName);
        player.addCash(sCash - player.getCash());
        while(player.getWins()!=sWins){
            player.incrementWins();
        }
        while(player.getLoses()!=sLoses){
            player.incrementLoses();
        }
    }
    else{
        beginMenu(true, "File does not exist.");
    }
}

//////////////* Printing Stuff *////

void Game::printInstructions(){
    clearscr();
    cout<<yellow<<Print::title_blackjack<<def<<"\n";
    cout<<"\n"<<lightGreen<<Print::instructions<<def<<"\n";
    getch();
}

void Game::printTop(){
    clearscr();
    cout<<yellow<<Print::title_blackjack<<def<<"\n";
    cout<<lightRed<<"\t\tCards: "<<deck.getSize()<<lightGreen<<"\t\tCash: "<<player.getCash()<<lightBlue<<"\t\tName: "<<player.getName()<<def<<"\n\n\n";
}

void Game::printBody(){
    printTop();
    cout<<lightRed<<Print::dealer_border<<def;
    dealer.printFirstCard();
    cout<<lightCyan<<Print::player_border<<def;
    player.printCards();
    cout << lightGreen<< "\nSum: "<<lightRed<< player.getSum()<<def;
}