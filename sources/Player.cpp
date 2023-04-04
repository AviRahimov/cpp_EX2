//
// Created by avi on 20/03/2023.
//
//using namespace std;
#include "player.hpp"
#include <string>
using namespace ariel;

Player::Player(){

}
Player::Player(string str){

}
int Player::stacksize(){
    return 0;
}
int Player::cardesTaken(){
    return 0;
}
string Player::getName(){
    return this->name;
}
void Player::setName(string new_name){

}
int Player::getCardsLeft(){
    return 0;
}
void Player::setCardsLeft(int new_cards_left){

}
int Player::getWonCards(){
    return 0;
}
void Player::setWonCards( int new_won_cards){

}
bool Player::IsPlaying(){
    return this->is_playing;
}
void Player::setIsPlaying(bool new_playing_status){
    this->is_playing = new_playing_status;
}