#include<iomanip>

class PlayerSet{

    private:
        string name;             // Name of Player
        int cash, wins, loses;   // Stat Data
        // This class is almost similar to Player, but does not need vectors and betting values.

    public:
        PlayerSet();
        string getName();
        int getCash();
        int getWins();
        int getLoses();
        void setValues(string nm, int c, int w, int l);

};

//////////////* Default Constructor *////

PlayerSet::PlayerSet(){
    name = "N/A";
    cash=1000;
    wins=0;
    loses=0;
}

//////////////* Getter Functions *////

// Returns name of Player
string PlayerSet::getName(){
    return name;
}

// Returns cash of Player
int PlayerSet::getCash(){
    return cash;
}

// Returns wins of Player
int PlayerSet::getWins(){
    return wins;
}

// Returns loses of Player
int PlayerSet::getLoses(){
    return loses;
}

//////////////* Setter Function *////

void PlayerSet::setValues(string nm, int c, int w, int l){
    name = nm;
    cash = c;
    wins = w;
    loses = l;
}

//////////////////////////////////////////////////////////////////

class Statistics{

    private:
        PlayerSet p[3];                 // 3 Players

    public:
        Statistics();
        bool check(Player pl);
        void print();
        void saveStats();
        void loadStats();

};

//////////////* Default Constructor *////

Statistics::Statistics(){
    fstream temp;
    temp.open("data/statistics.bin", ios::in | ios::binary);
    if(temp.fail()){
        saveStats();
    }
    else{
        temp.close();
        loadStats();
    }
}

//////////////* Checks for High Score & Saves *////

bool Statistics::check(Player pl){
    bool rewrite = false;
    if(pl.getCash()>p[0].getCash()){
        p[0].setValues(pl.getName(), pl.getCash(), pl.getWins(), pl.getLoses());
        rewrite = true;
    }
    if(pl.getWins()>p[1].getWins()){
        p[1].setValues(pl.getName(), pl.getCash(), pl.getWins(), pl.getLoses());
        rewrite = true;
    }
    if(pl.getLoses()>p[2].getLoses()){
        p[2].setValues(pl.getName(), pl.getCash(), pl.getWins(), pl.getLoses());
        rewrite = true;
    }
    if(rewrite){
        saveStats();
    }
    return rewrite;
}

//////////////* Printing *////

void Statistics::print(){
    int maxlength = max(max(p[0].getName().length(), p[1].getName().length()),p[2].getName().length());
    for(int i=0;i<3;i++){
        switch(i){
            case 0: cout<<"MAX CASH  ||||||||| "; break;
            case 1: cout<<"MAX WINS  ||||||||| "; break;
            case 2: cout<<"MAX LOSES ||||||||| ";
        }
        cout<<setw(maxlength+1)<<p[i].getName()<<"\t | \t"<<lightGreen<<"Cash: "<<setw(7)<<p[i].getCash()<<"\t | \t"<<yellow<<"Wins: "<<setw(5)<<p[i].getWins()<<"\t | \t"<<lightRed<<"Loses: "<<setw(5)<<p[i].getLoses()<<def<<"\n";
    }
}

//////////////* File Handling *////

void Statistics::saveStats(){
    fstream f1;
    f1.open("data/statistics.bin", ios::out | ios::binary);
    for(int i=0;i<3;i++){
        string sName = p[i].getName();
        int nameSize = sName.size();
        int sCash = p[i].getCash();
        int sWins = p[i].getWins();
        int sLoses = p[i].getLoses();
        f1.write((char*)&nameSize, sizeof(nameSize));
        f1.write(sName.c_str(), sName.size());
        f1.write((char*)&sCash, sizeof(sCash));
        f1.write((char*)&sWins, sizeof(sWins));
        f1.write((char*)&sLoses, sizeof(sLoses));
    }
    f1.close();
}

void Statistics::loadStats(){
    fstream f1;
    f1.open("data/statistics.bin", ios::in | ios::binary);
    for(int i=0;i<3;i++){
        string sName;
        int nameSize;
        int sCash;
        int sWins;
        int sLoses;
        f1.read((char*)&nameSize, sizeof(nameSize));
        sName.resize(nameSize);
        f1.read(&sName[0], sName.size());
        f1.read((char*)&sCash, sizeof(sCash));
        f1.read((char*)&sWins, sizeof(sWins));
        f1.read((char*)&sLoses, sizeof(sLoses));
        p[i].setValues(sName, sCash, sWins, sLoses);
    }
    f1.close();
}