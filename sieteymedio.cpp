//
//  main.cpp
//  hw1
//
//  Created by Scott Moyer on 10/13/17.
//  Copyright © 2017 Scott Moyer. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"

//Function that takes in game information after each round and records the game log
void game_log(ofstream& game, int round, int money_amount, int bet, Hand player, Hand dealer){
    game << "------------------------------------------------\n";
    game << "Game number: " << round << "\t\tMoney remaining: $" << money_amount << std::endl;
    game << "Bet: $" << bet << std::endl;
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
    
    //Initializes Player and Hand objects for the player and dealer
    Player::Player you(100);
    Player::Player dealer(900);
    Hand::Hand yourhand;
    Hand::Hand dealerhand;
    
    //Initialize variables to be used throughout the game
    int bet;
    int round = 0;
    char drawagain;
    std::ofstream output;
    output.open("gamelog.txt");
    srand(time(0));
    bool draw = true;
    bool busted = false;
    
    //Checks to see if player or dealer has lost yet and prompts user to make a bet
    while(you.curr_money()>0 && dealer.curr_money()>0){
        std::cout << "You have: $" << you.curr_money() << ". Place your bet: $";
        std::cin >> bet;
        std::cin.ignore();

        //Checks for a valid bet
        while(bet>you.curr_money()){
            std::cout << "You only have $" << you.curr_money() << ". Please enter a valid bet: $";
            std::cin >> bet;
            std::cin.ignore();
        }
        
        //Draws and displays a card
        std::cout << "Your cards: " << std::endl;
        yourhand.draw_card();
        yourhand.curr_hand();
        
        //Checks to see if player wants to draw another card
        while(draw){
            std::cout << std::endl << "Your total is: " << yourhand.sum_hand() << ".";
            
            //Checks to see if player has busted
            if (yourhand.sum_hand() > 7.5){
                std::cout << std::endl << "You busted!" << std::endl;
                draw = false;
                busted = true;
            }
            
            //Asks player if they want to draw another card
            else {
                std::cout << " Do you want to draw again? (y/n) ";
                std::cin >> drawagain;
                std::cin.ignore();
                
                if (drawagain == 'n' || drawagain == 'N'){
                    draw = false;
                }
                else if (drawagain == 'y' || drawagain == 'Y'){
                    yourhand.draw_card();
                    std::cout << std::endl;
                    yourhand.curr_card();
                    std::cout << std::endl << "Your hand: " << std::endl;
                    yourhand.curr_hand();
                }

            }
            
        }

