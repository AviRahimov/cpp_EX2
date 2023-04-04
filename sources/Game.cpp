//
// Created by avi on 20/03/2023.
//
#include "game.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
using namespace ariel;
#define SIZE_OF_CARDS 52
string NUMBERS[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};

Game::Game(Player& p1, Player& p2): player1(p1), player2(p2){
    // checking if the stack sixe of each player greater than 0, otherwise they cannot play
    if(p1.stacksize()>0 || p2.stacksize()>0){
        throw invalid_argument("Current players are playing the game, you can't create a new game with them");
    }
     if(&p1 == &p2)
     {
        player1.setIsPlaying(false);
        player2.setIsPlaying(false);
     }
    else
    {
    DrawCount = 0;
    player1.setCardsLeft(26);
    player2.setCardsLeft(26);
    divide_cards_for_each_player(SIZE_OF_CARDS);
    player1.setIsPlaying(true);
    player2.setIsPlaying(true);
    }
}

void Game::playTurn(){
    if(player1.stacksize() > 0 && player2.stacksize() > 0 && player1.IsPlaying() == true && player2.IsPlaying() == true)
    {
        Card player1Card = player1.getDeckOfCards().back(); // get one card from player1's deck of cards
        Card player2Card = player2.getDeckOfCards().back(); // get one card from player2's deck of cards
        player1.RemoveCardFromDeck();
        player2.RemoveCardFromDeck();
        player1.setCardsLeft(player1.stacksize()-1); // after one turn, we need to decrease the number of stack of cards by 1.
        player2.setCardsLeft(player2.stacksize()-1);
        setCountCardsAddition(getCountCardsAddition()+2); // static integer because it's a recursive function so, I want to chnge thos variable every time calling the function
        if((player1Card.getNumber() == 1 && player2Card.getNumber() >2) || (player1Card.getNumber() == 2 && player2Card.getNumber() == 1) || (player1Card.getNumber() > 2 && player2Card.getNumber()<player1Card.getNumber() && player2Card.getNumber()!=1)) // The case that player1 won in one turn, The game rules said that 1 win all numbers between 3-13 but 2 win 1
        { 
            player1.addWonCards(getCountCardsAddition()); // adding the number of cards player1 won to his won_cards variable
            setCountCardsAddition(0); // setting this variable to 0 because now the table is empty from cards i.e. player1 won the cards
            string turn_stats = player1.getName() + " played " + NUMBERS[player1Card.getNumber()-1] + " of " + player1Card.getType() + " " + 
                                player2.getName() + " played " + NUMBERS[player2Card.getNumber()-1] + " of " + player2Card.getType() + " " + 
                                player1.getName() + " wins";
            this->TurnStats.push_back(turn_stats);
            return;
        }

        else if ((player2Card.getNumber() == 1 && player1Card.getNumber() >2) || (player2Card.getNumber() == 2 && player1Card.getNumber() == 1) || (player2Card.getNumber() > 2 && player1Card.getNumber()<player2Card.getNumber() && player1Card.getNumber()!=1)) // The case that player2 won in one turn
        {
            player2.addWonCards(getCountCardsAddition()); // adding the number of cards player2 won to his won_cards variable
            setCountCardsAddition(0);
            string turn_stats = player1.getName() + " played " + NUMBERS[player1Card.getNumber()-1] + " of " + player1Card.getType() + " " + 
                                player2.getName() + " played " + NUMBERS[player2Card.getNumber()-1] + " of " + player2Card.getType() + " " + 
                                player2.getName() + " wins";
            this->TurnStats.push_back(turn_stats);
            return;
        }

        else if(player2Card.getNumber() == player1Card.getNumber() && (player1.stacksize()>1 && player2.stacksize()>1))
        {
            this->DrawCount++; // adding 1 to this variable because it's a draw
            setCountCardsAddition(getCountCardsAddition()+2); // adding 2 because each player put one card upside-down
            string turn_stats = player1.getName() + " played " + to_string(player1Card.getNumber()) + " of " + player1Card.getType() + " " + 
                                player2.getName() + " played " + to_string(player2Card.getNumber()) + " of " + player2Card.getType() + " " + 
                                "draw";
            this->TurnStats.push_back(turn_stats);
            Card upside_down1 = player1.getDeckOfCards().back();
            Card upside_down2 = player2.getDeckOfCards().back();
            player1.RemoveCardFromDeck();
            player2.RemoveCardFromDeck();
            player1.setCardsLeft(player1.stacksize()-1);
            player2.setCardsLeft(player2.stacksize()-1);
            this->playTurn(); // call recursively to the current function until there is a won in some turn or there is only draw so the game will stop after all draws(next statement)
        }

        else // should check if this statement occur only if there is only draw
        {
            player1.addWonCards((getCountCardsAddition()+2)/2); // splitting the points between both players equally
            player2.addWonCards((getCountCardsAddition()+2)/2);
            player1.setCardsLeft(player1.stacksize()-1);
            player2.setCardsLeft(player2.stacksize()-1);
            player1.setIsPlaying(false); // the game finished so the players stopped playing
            player2.setIsPlaying(false);
            return;
        }
        }
    else
    {
        player1.setIsPlaying(false); // the game finished so the players stopped playing
        player2.setIsPlaying(false);
        throw runtime_error("You are trying to play with 0 cards or maybe one of the playes already playing");
    }    
}

void Game::printLastTurn(){
    cout << TurnStats.back() << endl;
    cout << TurnStats.back() << endl;
}

void Game::playAll(){
    while (player1.stacksize()>0  && (player1.IsPlaying() == true && player2.IsPlaying() == true))
    {
        playTurn();
        printLastTurn();
        cout << "Stack size for player1: " << player1.stacksize() << endl;
        cout << "Stack size for player1: " << player1.stacksize() << endl;
    }
    player1.setIsPlaying(false);
    player2.setIsPlaying(false);
}

void Game::printWiner(){
    if (player1.cardesTaken() > player2.cardesTaken())
    {
        cout << "The winner is " + player1->getName() << endl;
    }
    else if (player2.cardesTaken() > player1.cardesTaken())
    {
        cout << "The winner is " + player2->getName() << endl;
    }
    else
    {
        throw runtime_error("There is no winner, draw");
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
    int WinRatePlayer1 = round(((float(player1.cardesTaken())/SIZE_OF_CARDS) * 100)); // Win rate for player1 by percentage
    int WinRatePlayer2 = round(((float(player2.cardesTaken())/SIZE_OF_CARDS) * 100)); // Win rate for player2 by percentage
    cout << "Stats for " + player1.getName() + "\n" + "Win rate: " << WinRatePlayer1  << "%" << "\n" << "Cards Won: " << player1.cardesTaken() << endl;
    cout << "Stats for " + player2.getName() + "\n" + "Win rate: " << WinRatePlayer2  << "%" << "\n" << "Cards Won: " << player2.cardesTaken() << endl;
    cout << "Number of draws in this game was: " << this->DrawCount << endl;
}

void Game::divide_cards_for_each_player(int num_of_cards){
    vector<string> types = {"Hearts", "Spades", "Diamonds", "Clubs"};
    srand(time(0));
    vector<Card> cards;
    for (size_t i = 0; i < 13; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cards.push_back(Card(i+1, types[j]));
        }
    }
    random_device r;
    seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    mt19937 eng(seed);
    shuffle(cards.begin(), cards.end(), eng);
    for (size_t i = 0; i < num_of_cards; i++)
    {
        if(i%2 == 0)
        {
            player1.setCardInDeckOfCards(cards.at(i));
        }
        else
        {
            player2.setCardInDeckOfCards(cards.at(i));
        }
    }
}

void Game::setCountCardsAddition(int num){
    this->countCardsAddition = num;
}

int Game::getCountCardsAddition(){
    return this->countCardsAddition;
}
