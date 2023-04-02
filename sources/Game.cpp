//
// Created by avi on 20/03/2023.
//
#include "game.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;
#define SIZE_OF_CARDS 52
int Game::countCardsAddition = 0;

Game::Game(Player& p1, Player& p2){ //: player1("player1"), player2("player2"){
    if(p1.stacksize()>0 || p2.stacksize()>0){
        throw invalid_argument("Current players are playing the game, you can't create a new game with them");
    }
    if(&p1 == &p2){
        player1->setIsPlaying(false);
        player2->setIsPlaying(false);
    }
    else
    {
    player1 = &p1;
    player2 = &p2;
    DrawCount = 0;
    player1->setCardsLeft(26);
    player2->setCardsLeft(26);
    player1->setDeckOfCards(26);
    player2->setDeckOfCards(26);
    player1->setIsPlaying(true);
    player2->setIsPlaying(true);
    }
}

void Game::playTurn(){
    if(player1->stacksize() > 0 && player2->stacksize() > 0 && player1->IsPlaying() == true && player2->IsPlaying() == true)
    {
        Card player1Card = player1->getDeckOfCards().back(); // get one card from player1's deck of cards
        Card player2Card = player2->getDeckOfCards().back(); // get one card from player2's deck of cards
        player1->getDeckOfCards().pop_back();
        player2->getDeckOfCards().pop_back();
        countCardsAddition+=2; // static integer because it's a recursive function so, I want to chnge thos variable every time calling the function
        if((player1Card.getNumber() > player2Card.getNumber()) || (player1Card.getNumber()==1 && player2Card.getNumber()>2) || !(player1Card.getNumber()>2 && player2Card.getNumber()==1)) // The case that player1 won in one turn, The game rules said that 1 win all numbers between 3-13 but 2 win 1
        { 
            player1->addWonCards(countCardsAddition); // adding the number of cards player1 won to his won_cards variable
            player1->setCardsLeft(player1->getCardsLeft()-1); // after one turn, we need to decrease the number of stack of cards by 1.
            player2->setCardsLeft(player2->getCardsLeft()-1);
            countCardsAddition = 0; // setting this variable to 0 because now the table is empty from cards i.e. player1 won the cards
            string turn_stats = player1->getName() + " played " + to_string(player1Card.getNumber()) + " of " + player1Card.getType() + " " + 
                                player2->getName() + " played " + to_string(player2Card.getNumber()) + " of " + player2Card.getType() + " " + 
                                player1->getName() + " wins";
            this->TurnStats.push_back(turn_stats);
        }

        else if ((player2Card.getNumber() > player1Card.getNumber()) || (player2Card.getNumber()==1 && player1Card.getNumber()>2)) // The case that player2 won in one turn
        {
            player2->addWonCards(countCardsAddition); // adding the number of cards player2 won to his won_cards variable
            player1->setCardsLeft(player1->getCardsLeft()-1);
            player2->setCardsLeft(player2->getCardsLeft()-1);
            countCardsAddition = 0;
            string turn_stats = player1->getName() + "played" + to_string(player1Card.getNumber()) + "of" + player1Card.getType() + " " + 
                                player2->getName() + "played" + to_string(player2Card.getNumber()) + "of" + player2Card.getType() + " " + 
                                player2->getName() + "wins";
            this->TurnStats.push_back(turn_stats);
        }

        else if(player2Card.getNumber() == player1Card.getNumber() && (player1->getCardsLeft()>1 && player2->getCardsLeft()>1))
        {
            this->DrawCount++; // adding 1 to this variable because it's a draw
            countCardsAddition+=2; // adding 2 because each player put one card upside-down
            string turn_stats = player1->getName() + "played" + to_string(player1Card.getNumber()) + "of" + player1Card.getType() + 
                                player2->getName() + "played" + to_string(player2Card.getNumber()) + "of" + player2Card.getType() + 
                                "draw";
            this->TurnStats.push_back(turn_stats);
            Card upside_down1 = player1->getDeckOfCards().back();
            Card upside_down2 = player2->getDeckOfCards().back();
            player1->getDeckOfCards().pop_back();
            player2->getDeckOfCards().pop_back();
            player1->setCardsLeft(player1->getCardsLeft()-1);
            player2->setCardsLeft(player2->getCardsLeft()-1);
            this->playTurn(); // call recursively to the current function until there is a won in some turn or there is only draw so the game will stop after all draws(next statement)
        }

        else // should check if this statement occur only if there is only draw
        {
            player1->addWonCards(countCardsAddition/2); // splitting the points between both players equally
            player2->addWonCards(countCardsAddition/2);
            player1->setIsPlaying(false); // the game finished so the players stopped playing
            player2->setIsPlaying(false);
        }
        }
    else
    {
        player1->setIsPlaying(false); // the game finished so the players stopped playing
        player2->setIsPlaying(false);
        throw runtime_error("You are trying to play with 0 cards");
    }
       
}

void Game::printLastTurn(){
    cout << TurnStats.back() << endl;
}

void Game::playAll(){
    while (player1->stacksize()>0 && player2->stacksize()>0)
    {
        playTurn();
    }
}

void Game::printWiner(){
    if (player1->cardesTaken() > player2->cardesTaken())
    {
        cout << "The winner is " + player1->getName() << endl;
    }
    else if (player2->cardesTaken() > player1->cardesTaken())
    {
        cout << "The winner is " + player2->getName() << endl;
    }
    else
    {
        throw runtime_error("There is no winner, draw");
    }
}
void Game::printLog(){
    // printing all stats from the vector of stats I created, each call in the vector represent one turn info.
    for (string str : TurnStats)
    {
        cout << str << endl;
    }
}
void Game::printStats(){
    float WinRatePlayer1 = ((player1->cardesTaken())/(SIZE_OF_CARDS)) * 100; // Win rate for player1 by percentage
    float WinRatePlayer2 = ((player2->cardesTaken())/(SIZE_OF_CARDS)) * 100; // Win rate for player2 by percentage

    cout << "Stats for " + player1->getName() + "\n" + "Win rate: " << WinRatePlayer1  << "\n" << "Cards Won: " << player1->cardesTaken() << endl;
    cout << "Stats for " + player2->getName() + "\n" + "Win rate: " << WinRatePlayer2  << "\n" << "Cards Won: " << player2->cardesTaken() << endl;
    cout << "Number of draws in this game was: " << this->DrawCount << endl;
}