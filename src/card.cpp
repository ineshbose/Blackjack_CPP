#include "card.hpp"

Card::Card(){
    number = 0;
    suit = '\0';
    block = false;
}

Card::Card(int no, char s){
    number = no;
    suit = s;
    block = false;
}

int Card::getNumber(){
    return number;
}

char Card::getSuit(){
    return suit;
}  
bool Card::getBlock(){
    return block;
}

void Card::setNumber(int no){
    number = no;
}
void Card::setSuit(char c){
    suit = c;
}
void Card::setBlock(bool b){
    block = b;
}

char Card::getPrintNumber(){
    switch(number){
        case 1: return 'A';
        case 10: return 'X';
        case 11: return 'J';
        case 12: return 'Q';
        case 13: return 'K';
        default: char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
                    return digits[number];
    }
}
void Card::printCardL1(){
    switch(suit){
        case 'C': cout<<"| :(): |"; break;
        case 'H': cout<<"| (\\/) |"; break;
        case 'D':
        case 'S': cout<<"| :/\\: |"; break;
        default : cout<<"|  //  |";
    }
}

void Card::printCardL2(){
    switch(suit){
        case 'C': cout<<"| ()() |"; break;
        case 'H':
        case 'D': cout<<"| :\\/: |"; break;
        case 'S': cout<<"| (__) |"; break;
        default : cout<<"|  //  |";
    }
}