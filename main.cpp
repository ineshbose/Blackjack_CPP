#include <fstream>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "card.hpp"
#include "dealer.hpp"
#include "player.hpp"

using namespace std;


void clrscr(){
    system("cls");
}

bool deal(Player &p1, Dealer &d1){
    bool player = p1.addCard();
    bool dealer;
    if(d1.getSum()<18){
        dealer = d1.addCard();
    }
    return (player && dealer);
}

int main(){
    clrscr();
    srand(time(NULL));
    char name[100];
    char choice, hit='Y';
    bool status;
    cout << "Hello! What's your name?\n";
    cin>>name;
    Player player(name);
    Dealer dealer;
    clrscr();
    cout<<"Hello "; player.printName();
    while(hit!='N' && hit!='n'){
        status = deal(player, dealer);
        cout<<"\nYou hold: "<<player.getSum();
        cout<<"\nDealer holds: "<<dealer.getSum();
        if(status){
            cout<<"\nHit? ";
            cin>>hit;
        }
        else{
            cout<<"\nGame ended.";
            break;
        }
    }
    if(status){
        if(dealer.getSum()>player.getSum()){
            cout<<"\nDealer wins!";
        }
        else if(dealer.getSum()<player.getSum()){
            cout<<"\nYou win!";
        }
        else{
            cout<<"\nNeutral.";
        }
    }
    return 0;
}