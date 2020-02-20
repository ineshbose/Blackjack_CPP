#include <iostream>
#include <stdlib.h>

using namespace std;

class Card{

private:
    int number;
    char suit;
    bool block;

public:
    Card(){
        number = 0;
        suit = '\0';
        block = false;
    }
    Card(int no, char s){
        number = no;
        suit = s;
        block = false;
    }
    void setNumber(int no){
        number = no;
    }
    int getNumber(){
        return number;
    }
    void setSuit(char c){
        suit = c;
    }
    char getSuit(){
        return suit;
    }
    void setBlock(bool b){
        block = b;
    }
    bool getBlock(){
        return block;
    }
    void printCard(){
        cout<<" | "<<suit<<" : ";
        switch(number){
            case 1: cout<<"A"<<" | "; break;
            case 10: cout<<10<<"| "; break;
            case 11: cout<<"J"<<" | "; break;
            case 12: cout<<"Q"<<" | "; break;
            case 13: cout<<"K"<<" | "; break;
            default: cout<<number<<" | ";
        }
    }
};