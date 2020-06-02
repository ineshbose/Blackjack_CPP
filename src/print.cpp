#include "headers/print.hpp"
#include <iostream>
#include <sstream>

std::string Print::title_blackjack(){
    constexpr auto title_blackjack = R"(
    /$$$$$$$ /$$       /$$$$$$   /$$$$$$ /$$   /$$    /$$$$$  /$$$$$$   /$$$$$$ /$$   /$$
   | $$__  $| $$      /$$__  $$ /$$__  $| $$  /$$/   |__  $$ /$$__  $$ /$$__  $| $$  /$$/
   | $$  \ $| $$     | $$  \ $$| $$  \__| $$ /$$/       | $$| $$  \ $$| $$  \__| $$ /$$/ 
   | $$$$$$$| $$     | $$$$$$$$| $$     | $$$$$/        | $$| $$$$$$$$| $$     | $$$$$/ 
   | $$__  $| $$     | $$__  $$| $$     | $$  $$   /$$  | $$| $$__  $$| $$     | $$  $$ 
   | $$  \ $| $$     | $$  | $$| $$    $| $$\  $$ | $$  | $$| $$  | $$| $$    $| $$\  $$ 
   | $$$$$$$| $$$$$$$| $$  | $$|  $$$$$$| $$ \  $$|  $$$$$$/| $$  | $$|  $$$$$$| $$ \  $$
   |_______/|________|__/  |__/ \______/|__/  \__/ \______/ |__/  |__/\______/ |__/  \__/
    )";

    std::ostringstream toReturn;
    toReturn << title_blackjack;
    return toReturn.str();

}

std::string Print::begin_menu(){
    constexpr auto begin_menu = R"(
            1 - Start a New Game
            2 - Load from Game
            3 - Statistics
            4 - How to Play
            5 - Exit
    )";
    
    std::ostringstream toReturn;
    toReturn << begin_menu;
    return toReturn.str();
}

std::string Print::statistics(){
    constexpr auto statistics = R"(
     ____  ____  __  ____  __  ____  ____  __  ___  ____ 
    / ___)(_  _)/ _\(_  _)(  )/ ___)(_  _)(  )/ __)/ ___)
    \___ \  )( /    \ )(   )( \___ \  )(   )(( (__ \___ \
    (____/ (__)\_/\_/(__) (__)(____/ (__) (__)\___)(____/
    )";
    
    std::ostringstream toReturn;
    toReturn << statistics << "\n\n";
    return toReturn.str();
}
    
std::string Print::instructions(){
    constexpr auto instructions = R"(
            .-"-._,-'_`-._,-'_`-._,-'_`-._,-'_`-,_,-'_`-,_,-'_`-,_,-'_`-,_,-'_`-,_,-'_`-,.
            (  ,-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-~-} ;.
            \ \.'_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-._~--. \ .
            /\ \/ ,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._`./ \ \ .
            ( (`/ /      _   _                _         ____  _                  `/ /.) ) .
            \ \ / \     | | | | _____      __| |_ ___  |  _ \| | __ _ _   _       / / \ / .
            \ \') )     | |_| |/ _ \ \ /\ / /| __/ _ \ | |_) | |/ _` | | | |      ( (,\ \ .
            / \ / /     |  _  | (_) \ V  V / | || (_) ||  __/| | (_| | |_| |      \ / \ \ .
            ( (`/ /     |_| |_|\___/ \_/\_/   \__\___/ |_|   |_|\__,_|\__, |        / /.) ) .
            \ \ / \                                                   |___/       / / \ / .
            \ \') )                                                             ( (,\ \ . 
            / \ / /  1. The goal in Blackjack (aka Hit or Stand) is to beat       \ / \ \ . 
            ( (`/ /     the dealer's hand without going over 21.                    / /.) ) . 
            \ \ / \                                                               / / \ / . 
            \ \') )  2. Face cards are worth 10; Aces are worth 1 or 11.        ( (,\ \ . 
            / \ / /                                                               \ / \ \ .
            ( ( / /  3. To 'Hit' is ask for another card. To 'Stand' is to          / /.) ) .
            \ \ / \     hold your total and end your turn.                        / / \ /. 
            \ \') )                                                             ( (,\ \ . 
            / \ / /  4. If you go over 21, you bust and the dealer wins.          \ / \ \ .
            ( ( / /                                                                 / /.) ) . 
            \ \ / \  5. If you reach 21, you got a blackjack.                     / / \ / .
            \ \') )                                                             ( (,\ \ . 
            / \ / /  6. A higher sum means you win twice the amount you bet.      \ / \ \ .
            ( ( / /                                                                 / /.) ) .
            \ \ / \       _       _ (Press any key to continue) _       _         / / \ /.
            \ `.\ `-._,-'_`-._,-'_`-._,-'_`-._,-'_`-._,-'_`-._,-'_`-._-'_`-._,-'_/,\ \ . 
            ( `. `,~-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-=,' ,\ \ .
            `. `'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,"-' ; .
                `-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-.-' .
    )";

    std::ostringstream toReturn;
    toReturn << instructions;
    return toReturn.str();
}

std::string Print::bust(){
    constexpr auto bust = R"(
     ___            _    _ 
    | _ ) _  _  ___| |_ | |
    | _ \| || |(_-<|  _||_|
    |___/ \_,_|/__/ \__|(_)        
    )";

    std::ostringstream toReturn;
    toReturn << bust;
    return toReturn.str();
}

std::string Print::blackjack(){
    constexpr auto blackjack = R"(
     ___  _            _     _            _    _ 
    | _ )| | __ _  __ | |__ (_) __ _  __ | |__| |
    | _ \| |/ _` |/ _|| / / | |/ _` |/ _|| / /|_|
    |___/|_|\__,_|\__||_\_\_/ |\__,_|\__||_\_\(_)
                          |__/                   
    )";

    std::ostringstream toReturn;
    toReturn << blackjack;
    return toReturn.str();
}

std::string Print::dealer_wins(){
    constexpr auto dealer_wins = R"(
     ___           _                  _           
    |   \ ___ __ _| |___ _ _  __ __ _(_)_ _  ___  
    | |) / -_/ _` | / -_| '_| \ V  V | | ' \(_-<_ 
    |___/\___\__,_|_\___|_|    \_/\_/|_|_||_/__(_)                                            
    )";

    std::ostringstream toReturn;
    toReturn << dealer_wins;
    return toReturn.str();
}

std::string Print::you_win(){
    constexpr auto you_win = R"(
    __   __                    _        _ 
    \ \ / /___  _  _  __ __ __(_) _ _  | |
     \ V // _ \| || | \ V  V /| || ' \ |_|
      |_| \___/ \_,_|  \_/\_/ |_||_||_|(_)
    )";

    std::ostringstream toReturn;
    toReturn << you_win;
    return toReturn.str();
}

std::string Print::draw(){
    constexpr auto draw = R"(
     ___            _     _ 
    | _ \ _  _  ___| |_  | |
    |  _/| || |(_-<| ' \ |_|
    |_|   \_,_|/__/|_||_|(_)
    )";

    std::ostringstream toReturn;
    toReturn << draw;
    return toReturn.str();
}

std::string Print::dealer_border(){
    constexpr auto dealer_border = R"(
                     _  __ _     __ _ 
/)/)/)/)/)/)/)/)/)  | \|_ |_||  |_ |_)  /)/)/)/)/)/)/)/)/)
(/(/(/(/(/(/(/(/(/  |_/|__| ||__|__| \  (/(/(/(/(/(/(/(/(/  
    )";

    std::ostringstream toReturn;
    toReturn << dealer_border;
    return toReturn.str();
}

std::string Print::player_border(){
    constexpr auto player_border = R"(
                     _     _     __ _ 
/)/)/)/)/)/)/)/)/)  |_)|  |_|\/ |_ |_)  /)/)/)/)/)/)/)/)/)
(/(/(/(/(/(/(/(/(/  |  |__| | | |__| \  (/(/(/(/(/(/(/(/(/                          
    )";

    std::ostringstream toReturn;
    toReturn << player_border;
    return toReturn.str();
}