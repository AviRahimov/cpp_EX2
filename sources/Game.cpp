//
// Created by avi on 20/03/2023.
//
#include "game.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;
using namespace ariel;
<<<<<<< HEAD

=======
#define SIZE_OF_CARDS 52

int Game::countCardsAddition = 0;

>>>>>>> b0674f7 (almost finish game file, playAll func remained)
Game::Game(Player& player1, Player& player2){
// : player1(player1), player2(player2){
    if(player1.stacksize()>0 || player2.stacksize()>0){
        throw invalid_argument("Current players are playing the game, you can't create a new game with them");
    }
    this->player1 = player1;
    this->player2 = player2;
    this->DrawCount = 0;
    player1.setIsPlaying(true);
    player2.setIsPlaying(true);
}

void Game::playTurn(){
    Card player1Card = player1.getDeckOfCards().pop_back(); // get one card from player1's deck of cards
    Card player2Card = player2.getDeckOfCards().pop_back(); // get one card from player2's deck of cards
    countCardsAddition+=2; // static integer because it's a recursive function so, I want to chnge thos variable every time calling the function
    if(player1Card.getNumber() > player2Card.getNumber()) // The case that player1 won in one turn
    {
        player1.addWonCards(countCardsAddition); // adding the number of cards player1 won to his won_cards variable
        player1.setCardsLeft(player1.getCardsLeft()-1); // after one turn, we need to decrease the number of stack of cards by 1.
        player2.setCardsLeft(player2.getCardsLeft()-1);
        countCardsAddition = 0; // setting this variable to 0 because now the table is empty from cards i.e. player1 won the cards
        string turn_stats = player1.getName() + "played" + player1Card.getNumber() + "of" + player1Card.getType() + 
                            player2.getName() + "played" + player2Card.getNumber() + "of" + player2Card.getType() + 
                            player1.getName() + "wins";
        this->TurnStats.insert(turn_stats);
    }
    else if (player2Card.getNumber() > player1Card.getNumber())// The case that player2 won in one turn
    {
        player2.addWonCards(countCardsAddition); // adding the number of cards player2 won to his won_cards variable
        player1.setCardsLeft(player1.getCardsLeft()-1);
        player2.setCardsLeft(player2.getCardsLeft()-1);
        countCardsAddition = 0;
        string turn_stats = player1.getName() + "played" + player1Card.getNumber() + "of" + player1Card.getType() + 
                            player2.getName() + "played" + player2Card.getNumber() + "of" + player2Card.getType() + 
                            player2.getName() + "wins";
        this->TurnStats.insert(turn_stats);
    }
    else if(player2Card.getNumber() == player1Card.getNumber() && (player1.getCardsLeft()>1 && player2.getCardsLeft()>1))
    {
        this->DrawCount++; // adding 1 to this variable because it's a draw
        countCardsAddition+=2; // adding 2 because each player put one card upside-down
        string turn_stats = player1.getName() + "played" + player1Card.getNumber() + "of" + player1Card.getType() + 
                            player2.getName() + "played" + player2Card.getNumber() + "of" + player2Card.getType() + 
                            "draw";
        this->TurnStats.insert(turn_stats);
        Card upside-down1 = player1.getDeckOfCards().pop_back();
        Card upside-down2 = player2.getDeckOfCards().pop_back();
        player1.setCardsLeft(player1.getCardsLeft()-1);
        player2.setCardsLeft(player2.getCardsLeft()-1);
        this->playTurn(); // call recursively to the current function until there is a won in some turn or there is only draw so the game will stop after all draws(next statement)
    }
    else
    {
        player1.addWonCards(SIZE_OF_CARDS/2); // splitting the points between both players equally
        player2.addWonCards(SIZE_OF_CARDS/2);
        player1.setIsPlaying(false); // the game finished so the players stopped playing
        player2.setIsPlaying(false);
    }
    
        
}

void Game::printLastTurn(){
    cout << this->TurnStats.back() << endl;
}

void Game::playAll(){

}

void Game::printWiner(){
    if (this->player1.cardesTaken() > this->player2.cardesTaken())
    {
        cout << "The winner is " + player1.getName() << endl;
    }
    else if (this->player2.cardesTaken() > this->player1.cardesTaken())
    {
        cout << "The winner is " + player2.getName() << endl;
    }
    else
    {
        cout << "There is no winner, draw between two players";
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
    float WinRatePlayer1 = ((player1.cardesTaken())/(SIZE_OF_CARDS/2)) * 100; // Win rate for player1 by percentage
    float WinRatePlayer2 = ((player2.cardesTaken())/(SIZE_OF_CARDS/2)) * 100; // Win rate for player2 by percentage

    cout << "Stats for " + player1.getName() + "\n" + "Win rate: " + WinRatePlayer1  + "\n" + "Cards Won: " + player1.cardesTaken() << endl;
    cout << "Stats for " + player2.getName() + "\n" + "Win rate: " + WinRatePlayer2  + "\n" + "Cards Won: " + player2.cardesTaken() << endl;
    cout << "Number of draws in this game was: " + this->DrawCount << endl;
}