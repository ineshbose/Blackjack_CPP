#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

void clrscr(){
    system("cls");
}

class Card{

    private: int number;
    public:
            int getNumber(){
                return number;
            }

};

class Dealer{

    private: Card cards[5];
             int sum;
    public:
             void revealCards(Card copyCards[]){
                 copyCards = cards;
             }

             void deal(){

             }

};

class Player{

    private: char name[100];
             Card cards[5];
             int sum, cash, bet;
    public: Player(char pname[100]){
                strcpy(name,pname);
            }
            void printName(){
                cout<<name;
            }

};

int main(){
    clrscr();
    char name[100];
    cout<<"Hello! What's your name?\n";
    cin>>name;
    Player player(name);
    player.printName();
    return 0;
}