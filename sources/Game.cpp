//
// Created by avi on 20/03/2023.
//
#include "game.hpp"
#include <stdexcept>
#include <string>
using namespace std;
using namespace ariel;

Game::Game(Player& player1, Player& player2){
// : player1(player1), player2(player2){
    if(player1.stacksize()>0 || player2.stacksize()>0){
        throw invalid_argument("Current players are playing the game, you can't create a new game with them");
    }
    this->player1 = player1;
    this->player2 = player2;
    player1.setIsPlaying(true);
    player2.setIsPlaying(true);
}
Game::Game(){

}
void Game::playTurn(){

}
void Game::printLastTurn(){

}
void Game::playAll(){

}
void Game::printWiner(){

}
void Game::printLog(){

}
void Game::printStats(){

}