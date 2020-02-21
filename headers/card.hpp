class Card{
    
    private:
        int number; // Card Number
        char suit;  // Card Suit
        bool block; // Boolean value for Ace Switching

    public:
        // Default Constructor
        Card(){
            number = 0;
            suit = '\0';
            block = false;
        }
        // Parameterised Constructor (for initializing deck)
        Card(int no, char s){
            number = no;
            suit = s;
            block = false;
        }
        // Getter Functions    
        int getNumber(){
            return number;
        }
        char getSuit(){
            return suit;
        }  
        bool getBlock(){
            return block;
        }
        // Setter Functions
        void setNumber(int no){
            number = no;
        }
        void setSuit(char c){
            suit = c;
        }
        void setBlock(bool b){
            block = b;
        }
        // Printing Card Details
        char getPrintNumber(){
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
        void printCardL1(){
            switch(suit){
                case 'C': cout<<"| :(): |"; break;
                case 'H': cout<<"| (\\/) |"; break;
                case 'D':
                case 'S': cout<<"| :/\\: |"; break;
                default : cout<<"|  //  |";
            }
        }

        void printCardL2(){
            switch(suit){
                case 'C': cout<<"| ()() |"; break;
                case 'H':
                case 'D': cout<<"| :\\/: |"; break;
                case 'S': cout<<"| (__) |"; break;
                default : cout<<"|  //  |";
            }
        }
};