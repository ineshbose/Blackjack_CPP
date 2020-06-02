#include "headers/dealer.hpp"
#include <iostream>


// Prints first card revealed and second card hidden
void Dealer::printFirstCard(){
    std::cout<<"\n";
    std::cout<<".------..------."<<"\n";
    std::cout<<"|"<<hand[0].getPrintNumber()<<".--. || .--. |"<<"\n";
    hand[0].printCardL1(); std::cout<<"|  //  |"<<"\n";
    hand[0].printCardL2(); std::cout<<"|  //  |"<<"\n";
    std::cout<<"| '--'"<<hand[0].getPrintNumber()<<"|| '--' |"<<"\n";
    std::cout<<"`------'`------'"<<"\n";
}