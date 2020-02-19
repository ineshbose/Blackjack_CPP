#include <iostream>
#include <stdlib.h>

using namespace std;

class Card{

private:
    int number;
    char suit;

public:
    Card(){
        number = 0;
        suit = '\0';
    }
    Card(int no, char s){
        number = no;
        suit = s;
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
    void printCard(){
        // ┌───────┐ 
        cout<<" | "<<suit<<" : ";
        switch(number){
            case 1: cout<<"A"<<" | "; break;
            case 10: cout<<10<<"| "; break;
            case 11: cout<<"J"<<" | "; break;
            case 12: cout<<"Q"<<" | "; break;
            case 13: cout<<"K"<<" | "; break;
            default: cout<<number<<" | ";
        }
        /*
        if(number<10){
            cout<<" | ";
        }
        else{
            cout<<"| ";
        }*/
    }

    void aceSwitch(bool up){
        if(up){
            number=11;
        }
        else{
            number=1;
        }
    }
};