class Player{

private:
    string name;        // Name of Player
    vector<Card> hand;  // Player's Cards
    int sum, cash, bet; // Cards' Sum, Player's Cash, Player's Bet
    int wins, loses;    // Player's Stats (number of wins and loses)

public:
    Player();
    string getName();
    int getBet();
    int getCash();
    int getSum();
    int getWins();
    int getLoses();
    void setName(string nm);
    bool setBet(int b);
    void addCash(int c);
    void incrementWins();
    void incrementLoses();
    void switchAce();
    void addCard(Card C);
    void clearCards();
    void printCards();
};


//////////////* Default Constructor *////

Player::Player(){
    name = "Unknown";
    sum = 0;
    bet = 0;
    cash = 1000;
    wins = 0;
    loses = 0;
}

//////////////* Getter Functions *////

// Returns name of Player
string Player::getName(){
    return name;
}

// Returns amount of bet
int Player::getBet(){
    return bet;
}

// Returns Player's cash amount
int Player::getCash(){
    return cash;
}

// Returns Player's card's sum to check end of game
int Player::getSum(){
    switchAce();
    return sum;
}

// Returns Player's statistic (number of wins)
int Player::getWins(){
    return wins;
}

// Returns Player's statistic (number of loses)
int Player::getLoses(){
    return loses;
}

//////////////* Setter Functions *////

// Sets name of Player
void Player::setName(string nm){
    name = nm;
}

// Sets bet for game
bool Player::setBet(int b){
    if(b<=cash){
        cash-=b;
        bet=b;
        return true;
    }
    else{
        return false;
    }
}

// Adds cash to Player's cash amount
void Player::addCash(int c){
    cash+=c;
}

// Increments Player's number of wins by one
void Player::incrementWins(){
    wins+=1;
}

// Increments Player's number of loses by one
void Player::incrementLoses(){
    loses+=1;
}

//////////////* Game Functions *////

// Switches Ace between 1 and 11
void Player::switchAce(){
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

// Adds card to player's hand
void Player::addCard(Card c){
    hand.push_back(c);
    if(c.getNumber()>10){
        c.setNumber(10);
    }
    else if (c.getNumber()==1){
        c.setNumber(11);
    }
    sum+= c.getNumber();
}

// Clears player's hand
void Player::clearCards(){
    hand.clear();
    sum=0;
}

// Prints player's cards
void Player::printCards(){
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