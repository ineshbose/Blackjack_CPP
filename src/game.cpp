#include "headers/game.hpp"
#include "headers/compatible.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

//////////////* Default Constructor *////

Game::Game(){
    deck.initializeDeck();
}

//////////////* Deals dealer towards the end *////

bool Game::dealDealer(){
    if(dealer.getSum()<player.getSum()){
        while (dealer.getSum() < 17){
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
        std::cout<<lightYellow<<Print::you_win()<<def<<"\n    (Dealer has "<<dealer.getSum()<<")\n";
        return 'p';
    }
    else if(dealer.getSum()>player.getSum()){
        printTop();
        std::cout<<lightRed<<Print::dealer_wins()<<def<<"\n    ("<<dealer.getSum()<<")\n";
        return 'd';
    }
    else{
        printTop();
        std::cout<<lightMagenta<<Print::draw()<<def;
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
        std::cout<<red<<Print::bust()<<def<<"\n    [Dealer : "<<dealer.getSum()<<" | "<<player.getName()<<" : "<<player.getSum()<<"]\n";
        if(dealer.getSum()>21){
            return 'p';
        }
        else if(player.getSum()>21){
            return 'd';
        }
    }
    else if(dealer.getSum()==21 || player.getSum()==21){
        printTop();
        std::cout<<lightGreen<<Print::blackjack()<<def<<"\n    [Dealer : "<<dealer.getSum()<<" | "<<player.getName()<<" : "<<player.getSum()<<"]\n";
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

bool Game::startBet(){
    if(player.getCash()>0){
        while(true){
            printTop();
            std::cout<<"Place your bet!\t\t $"<<green<<player.getBet()<<def<<"\n[W = Raise Bet | S = Decrease Bet | R = Done]\n";
            int c = toupper(getch());
            switch(c){
                case 87: if(player.getCash()>=5){
                            player.setBet(5);
                         }
                         break;
                case 83: if(player.getBet()>=5){
                            player.setBet(-5);
                         }
                         break;
            }
            if(c==82) break;
        }
        return true;
    }
    else{
        return false;
    }
}

bool Game::startGame(){
    player.addCard(deck.deal());
    dealer.addCard(deck.deal());
    player.addCard(deck.deal());
    dealer.addCard(deck.deal());
    printBody();
    if(checkWins()){
        return false;
    }
    while(true){
        std::cout << lightYellow << "\n\nH : Hit | S : Stand\n"<<def;
        int c = toupper(getch());
        if(c==72){
            player.addCard(deck.deal());
            printBody();
            if(checkWins()) return false;
        }
        else if(c==83){
            break;
        }
    }
    return true;
}

void Game::beginGame(){
    char cont;
    do{
        if(deck.getSize()<36){
                deck.initializeDeck();
        }
        player.clearCards();
        dealer.clearCards();
        if(!startBet()){
            std::cout<<lightRed<<"\nBankrupt! Game over.\n"<<def;
            break;
        }
        if (startGame()){
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
        std::cout<<lightRed<<Print::dealer_border()<<def;
        dealer.printCards();
        std::cout<<lightCyan<<Print::player_border()<<def;
        player.printCards();
        std::cout << yellow << "\nYour wins: " << player.getWins()<< lightRed <<"\nYour loses: "<<player.getLoses()<<def<<"\n";
        if(s.check(player)){
            std::cout<< lightYellow << "High Score!\n"<<def;
        }
        std::cout<<"\nContinue playing? [Y/N]: ";
        std::cin>>cont;
    } while (cont != 'N' && cont != 'n');
    char saveChoice;
    std::cout<<"\nSave game? [Y/N]: ";
    std::cin>>saveChoice;
    if(saveChoice == 'Y' || saveChoice == 'y'){
        saveGame();
    }
}

//////////////* Main Method to be Called *////

void Game::beginMenu(bool rep, std::string message){
    clearscr();
    std::cout<<yellow<<Print::title_blackjack()<<def<<"\n";
    std::cout<<Print::begin_menu()<<"\n";
    if(rep){
        std::cout<<red<<message<<def<<"\n";
    }
    char c;
    std::cout<<"Input : ";
    std::cin>>c;
    switch(c){
        case '1': char nm[100];
                  std::cout<<"Enter player name: ";
                  std::cin>>nm;
                  player.setName(nm);
                  beginGame();
                  break;
        case '2': loadGame();
                  beginGame();
                  break;
        case '3': printStatistics();
                  beginMenu(false, "");
                  break;
        case '4': printInstructions();
                  beginMenu(false, "");
                  break;
        case '5': exit(0);
                  break;
        default: beginMenu(true, "Invalid input.");
    }
}

//////////////* Data File Handling *////

void Game::saveGame(){
    std::fstream f1,f2;
    std::string filename;
    std::string path = "data/";
    do{
    std::cout<<"Enter filename: ";
    std::cin>>filename;
    std::transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
    }while(filename.compare("statistics")==0);
    path+=filename+".bin";
    std::string sName = player.getName();
    int sCash = player.getCash();
    int sWins = player.getWins();
    int sLoses = player.getLoses();
    int nameSize = sName.size();
    f2.open(path, std::ios::in | std::ios::binary);
    if(!f2.fail()){
        char choice;
        std::cout<<red<<"File already exists."<<def<<" Do you want to overwrite it? [Y/N]: ";
        std::cin>>choice;
        if(choice == 'N' || choice == 'n'){
            saveGame();
        }
    }
    f2.close();
    f1.open(path, std::ios::out | std::ios::binary);
    f1.write((char*)&nameSize, sizeof(nameSize));
    f1.write(sName.c_str(), sName.size());
    f1.write((char*)&sCash, sizeof(sCash));
    f1.write((char*)&sWins, sizeof(sWins));
    f1.write((char*)&sLoses, sizeof(sLoses));
    f1.close();
}

void Game::loadGame(){
    std::fstream f1;
    std::string filename;
    std::string path = "data/";
    do{
    std::cout<<"Enter filename: ";
    std::cin>>filename;
    std::transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
    }while(filename.compare("statistics")==0);
    path+=filename+".bin";
    f1.open(path, std::ios::in | std::ios::binary);
    if(!f1.fail()){
        std::string sName;
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

void Game::printStatistics(){
    clearscr();
    std::cout<<yellow<<Print::title_blackjack()<<def<<"\n";
    std::cout<<"\n"<<lightGreen<<Print::statistics()<<def<<"\n";
    s.print();
    std::cout<<"\n\n\t(Press any key to continue)\n";
    getch();
}

void Game::printInstructions(){
    clearscr();
    std::cout<<yellow<<Print::title_blackjack()<<def<<"\n";
    std::cout<<"\n"<<lightGreen<<Print::instructions()<<def<<"\n";
    getch();
}

void Game::printTop(){
    clearscr();
    std::cout<<yellow<<Print::title_blackjack()<<def<<"\n";
    std::cout<<lightRed<<"\t\tCards: "<<deck.getSize()<<lightGreen<<" \tCash: "<<player.getCash()<<lightMagenta
             <<" \tBet: "<<player.getBet()<<lightBlue<<" \tName: "<<player.getName()<<def<<"\n\n\n";
}

void Game::printBody(){
    printTop();
    std::cout<<lightRed<<Print::dealer_border()<<def;
    dealer.printFirstCard();
    std::cout<<lightCyan<<Print::player_border()<<def;
    player.printCards();
    std::cout << lightGreen<< "\nSum: "<<lightRed<< player.getSum()<<def<<"\n";
}