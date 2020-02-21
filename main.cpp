#include <fstream>
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include "game.hpp"

using namespace std;

int main(){
    system("cls");
    srand(time(NULL));
    Game game;
    game.beginMenu(false, "");
    return 0;
}