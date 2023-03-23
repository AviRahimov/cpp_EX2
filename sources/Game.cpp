//
// Created by avi on 20/03/2023.
//
#include "game.hpp"

Game::Game(Player player1, Player player2){
    if(player1.stacksize)
    this->player1 = player1;
    this->player2 = player2;
}
Game::Game(){

}
void Game::playTurn(){

}
void Game::printLastTurn(){

}
void Game::playAll (){

}
void Game::printWiner(){

}
void Game::printLog(){

}
void Game::printStats(){

}
Player Game::getPlayer1(){
    return this->player1;
}
Player Game::getPlayer2(){
    return this->player2;
}
void Game::setPlayer1(Player newPlayer1){

}
void Game::setPlayer2(Player newPlayer2){

}