class Dealer{
    
    private:
        vector<Card> hand; // Dealer's Cards
        int sum;           // Cards' Sum

    public:
        Dealer();
        int getSum();
        void switchAce();
        void addCard(Card c);
        void printFirstCard();
        void clearCards();
        void printCards();
};

// Default Constructor
Dealer::Dealer(){
    sum = 0;
}

// Getter Function for sum to check end of game
int Dealer::getSum(){
    switchAce();
    return sum;
}

// Switches Ace between 1 and 11
void Dealer::switchAce(){
    if(sum>21){
        for(int i=0;i<hand.size();i++){
                if(hand[i].getNumber()==1 && !(hand[i].getBlock())){
                    hand[i].setBlock(true);
                    sum-=10;
                    return;
                }
        }
    }
}

// Adds card to dealer's hand
void Dealer::addCard(Card c){
    hand.push_back(c);
    if(c.getNumber()>10){
        c.setNumber(10);
    }
    else if (c.getNumber()==1){
        c.setNumber(11);
    }
    sum+= c.getNumber();
}

// Prints first card revealed and second card hidden
void Dealer::printFirstCard(){
    cout<<"\n";
    cout<<".------..------."<<"\n";
    cout<<"|"<<hand[0].getPrintNumber()<<".--. || .--. |"<<"\n";
    hand[0].printCardL1(); cout<<"|  //  |"<<"\n";
    hand[0].printCardL2(); cout<<"|  //  |"<<"\n";
    cout<<"| '--'"<<hand[0].getPrintNumber()<<"|| '--' |"<<"\n";
    cout<<"`------'`------'"<<"\n";
}

// Clears dealer's hand
void Dealer::clearCards(){
    hand.clear();
    sum = 0;
}

// Prints dealer's cards
void Dealer::printCards(){
    cout<<"\n";
    for(int i=0;i<6;i++){
        for(int j=0;j<hand.size();j++){
            switch(i){
                case 0: cout<<".------."; break;
                case 1: cout<<"|"<<hand[j].getPrintNumber()<<".--. |"; break;
                case 2: hand[j].printCardL1(); break;
                case 3: hand[j].printCardL2(); break;
                case 4: cout<<"| '--'"<<hand[j].getPrintNumber()<<"|"; break;
                case 5: cout<<"`------'";
            }
        }
        cout<<"\n";
    }
}