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
        cout<<"| "<<suit<<": "<<number<<" | ";
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