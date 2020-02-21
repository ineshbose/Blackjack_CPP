#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include "print.hpp"
#include "color.hpp"
#include "card.hpp"
#include "dealer.hpp"
#include "player.hpp"
#include "deck.hpp"

using namespace std;

class Game{
    private:
        Player player;
        Dealer dealer;
        Deck deck;
    public:
        Game();
        char compareSum();
        char checkEnd();
        Card deal();
        bool checkWins();
        int startGame();
        bool dealDealer();
        void beginMenu(bool rep, string message);
        void saveGame();
        void loadGame();
        void startBet();
        void beginGame();
};

Game::Game(){
    deck.initializeDeck();
}

char Game::compareSum(){
    if(player.getSum()>dealer.getSum()){
        cout<<player.getName()<<" wins! (Dealer has "<<dealer.getSum()<<")";
        return 'p';
    }
    else if(dealer.getSum()>player.getSum()){
        cout<<"Dealer wins! ("<<dealer.getSum()<<")";
        return 'd';
    }
    else{
        cout<<"Draw!";
        return 'n';
    }
}

char Game::checkEnd(){
    if(dealer.getSum()>21 || player.getSum()>21){
        cout<<"\nBust! [Dealer: "<<dealer.getSum()<<", "<<player.getName()<<": "<<player.getSum()<<"]";
        if(dealer.getSum()>21){
            return 'p';
        }
        else if(player.getSum()>21){
            return 'd';
        }
    }
    else if(dealer.getSum()==21 || player.getSum()==21){
        cout<<"\nBlackjack! [Dealer: "<<dealer.getSum()<<", "<<player.getName()<<": "<<player.getSum()<<"]";
        if(dealer.getSum()==21){
            return 'd';
        }
        else if(player.getSum()==21){
            return 'p';
        }
    }
    return 'f';
}

int Game::startGame(){
    cout << "Bet placed. You now have $" << player.getCash() << endl;
    player.addCard(deck.deal());
    dealer.addCard(deck.deal());
    player.addCard(deck.deal());
    dealer.addCard(deck.deal());
    cout<<"\n====== DEALER ========\n";
    dealer.printFirstCard();
    cout<<"\n======================\n";
    player.printCards();
    cout << "\nSum: "<<player.getSum();
    if(checkWins()){
        return 0;
    }
    char choice;
    cout<<"\nHit or Stand? (H/S): ";
    cin>>choice;
    while(choice=='H' || choice=='h'){
        player.addCard(deck.deal());
        player.printCards();
        cout<<"\nSum: "<<player.getSum();
        if (checkWins()){
            return 0;
        }
        cout << "\nHit or Stand? (H/S): ";
        cin >> choice;
    }
    return 1;
}

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

void Game::startBet(){
    int b;
    cout<< "Place your bet!\t\tCash: $"<<player.getCash()<<"\n\t"<<red<<"5\t"<<green<<"25\t"<<blue<<"50\t"<<magenta<<"100\t\n"<<def;
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

void Game::beginGame(){
    char cont = 'Y';
    while(cont!='N' && cont!='n'){
        system("cls");
        cout<<yellow<<Print::title_blackjack<<def<<endl;
        if(deck.getSize()<36){
                cout<<"Reshuffling..\n";
                deck.initializeDeck();
        }
        cout<<"Cards: "<<deck.getSize()<<endl;
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
        dealer.printCards();
        cout << "\nYour wins: " << player.getWins()<<"\nYour loses: "<<player.getLoses();
        cout<<"\nContinue playing? [Y/N]: ";
        cin>>cont;
    }
    char saveChoice;
    cout<<"Save game? [Y/N]: ";
    cin>>saveChoice;
    if(saveChoice == 'Y' || saveChoice == 'y'){
        saveGame();
    }
}

void Game::beginMenu(bool rep, string message){
    system("cls");
    cout<<yellow<<Print::title_blackjack<<def<<endl;
    cout<<Print::begin_menu<<endl;
    if(rep){
        cout<<red<<message<<def<<endl;
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
        case 3: exit(0);
                break;
        default: beginMenu(true, "Invalid input.");
    }
}

void Game::saveGame(){
    fstream f1;
    string filename;
    string path = "Data/";
    cout<<"Enter filename: ";
    cin>>filename;
    path+=filename+".bin";
    string sName = player.getName();
    int sCash = player.getCash();
    int sWins = player.getWins();
    int sLoses = player.getLoses();
    int nameSize = sName.size();
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
    string path = "Data/";
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