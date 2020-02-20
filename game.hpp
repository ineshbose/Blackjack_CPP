#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Game{
    private:
        Player player;
        Dealer dealer;
        Deck deck;
    public:
        Game(Player p, Dealer d, Deck dec){
            player = p;
            dealer = d;
            deck = dec;
        }
        char compareSum();
        char checkEnd();
        Card deal();
        bool checkWins();
        int startGame();
        bool dealDealer();
        void beginGame();
        void saveGame();
        void loadGame();
};

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
}

void Game::beginGame(){
    if(deck.getSize()<36){
            cout<<"Reshuffling..\n";
            deck.initializeDeck();
    }
    cout<<"Cards: "<<deck.getSize()<<endl;
    player.clearCards();
    dealer.clearCards();
    int bet;
    cout << "Place your bet!\n";
    cout << player.getName() << " has $" << player.getCash() << "\nBet: ";
    cin >> bet;
    if (player.setBet(bet)){
        if (startGame() == 1){
            if (dealDealer()){
                switch (compareSum()){
                case 'p': player.incrementWins(); 
                          player.addCash((player.getBet()*2));
                          break;
                case 'd': player.incrementLoses(); break;
                case 'n': player.addCash(player.getBet()); break;
                }
            }/*
            else{
                //player.incrementWins();
            }
        }
        else{
            //return;
        }*/
        }
        dealer.printCards();
        cout << "\nYour wins: " << player.getWins()<<"\nYour loses: "<<player.getLoses();
    }
    else{
        cout<<"You don't have enough cash.\n";
        beginGame();
    }
}

void Game::saveGame(){
    fstream f1;
    char filename[50];
    char path[100] = "Data/";
    cout<<"Enter filename: ";
    cin>>filename;
    strcat(path, filename);
    strcat(path, ".bin");
    f1.open(path, ios::out | ios::binary);
    f1.write((char*)&player, sizeof(player));
    f1.close();
}

void Game::loadGame(){
    fstream f1;
    char filename[50];
    char path[100] = "Data/";
    cout<<"Enter filename: ";
    cin>>filename;
    strcat(path, filename);
    strcat(path, ".bin");
    f1.open(path, ios::in | ios::binary);
    f1.read((char*)&player, sizeof(player));
    f1.close();
}