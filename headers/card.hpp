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