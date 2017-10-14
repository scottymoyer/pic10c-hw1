//
//  main.cpp
//  hw1
//
//  Created by Scott Moyer on 10/12/17.
//  Copyright © 2017 Scott Moyer. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"

void game_log(ofstream& game, int round, int money_amount, int bet, Hand player, Hand dealer){
    game << "------------------------------------------------\n";
    game << "Game number: " << round << "\tMoney remaining: $" << money_amount << std::endl;
    game << "Bet:" << bet << std::endl;
    game << "Your cards: " << std::endl;
    for (int i = 0; i < player.handsize(); i++){
        game << "\t" << player.get_card(i) << std::endl;
    }
    game << "Your total: " << player.sum_hand() << std::endl << std::endl;
    game << "Dealer's cards: " << std::endl;
    for (int i = 0; i < dealer.handsize(); i++){
        game << "\t" << dealer.get_card(i) << std::endl;
    }
    game << "Dealer's total: " << dealer.sum_hand() << std::endl;
    
}

int main(){

    return 0;
}
