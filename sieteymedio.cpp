#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"

void game_log(std::ofstream& game, int round, int money_amt, int bet, Hand Player, Hand Dealer) {
	game << "------------------------------------------------\n\n";
	game << "Game number: " << round << "\t Money remaining: " << money_amt << "\n";
	game << "Bet: " << bet << "\n\n";
	//To be continued
}


int main()
{
    return 0;
}
