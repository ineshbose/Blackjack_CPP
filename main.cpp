#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int randomize();

void clrscr(){
    system("cls");
}

class Card{

    private: int number;
    public:
            int getNumber(){
                return number;
            }

            void dealCard(){
                number = (rand()%13)+1;
            }

};

class Dealer{

    private: Card cards[5];
             int sum, index, win;
    public: Dealer(){
                index = 0;
                sum = 0;
                win = 0;
            }
            int checkSum(){
                if(sum>21){
                    win = 2;
                }
                if(sum==21){
                    win = 3;
                }
                return win;
            }
            bool addCard(){
                cards[index].dealCard();
                sum+=cards[index].getNumber();
                index++;
                if(checkSum() == 2){
                    cout<<"\nDealer loses!";
                    return false;
                }
                return true;
            }
             int getSum(){
                 return sum;
             }

};

class Player{

    private: char name[100];
             Card cards[5];
             int sum, cash, bet, index;
             int win;
    public: Player(char pname[100]){
                strcpy(name,pname);
                index=0;
                sum=0;
                cash=5000;
                win=0;
            }
            int checkSum(){
                if(sum>21){
                    win = 2;
                }
                return win;
            }
            void printName(){
                cout<<name;
            }
            bool addCard(){
                cards[index].dealCard();
                sum+=cards[index].getNumber();
                index++;
                if(checkSum() == 2){
                    cout<<"\nYou lose!";
                    return false;
                }
                return true;
            }
            int getSum(){
                return sum;
            }

};

void deal(Player &p1, Dealer &d1){
    bool player = p1.addCard();
    bool dealer;
    if(d1.getSum()<19){
        dealer = d1.addCard();
    }
}

int main(){
    clrscr();
    char name[100];
    char choice, quit='n';
    cout<<"Hello! What's your name?\n";
    cin>>name;
    Player player(name);
    Dealer dealer;
    clrscr();
    cout<<"Hello! "; player.printName();
    while(quit!='Y'){
        cout<<"\nDeal card?";
        cin>>choice;
        switch(choice){
            case 'd':
            case 'D': deal(player, dealer);
        }
        cout<<player.getSum();
        cout<<"\nQuit?";
        cin>>quit;
    }
    return 0;
}