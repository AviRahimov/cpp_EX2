//
// Created by avi on 20/03/2023.
//

// This file contains the implementation of the Player class, which represents a player in a card game.
// Include the header file that declares the Player class.
#include "player.hpp"
#include <string>
#include <stdexcept>
using namespace ariel;

// Constructor that initializes the name and the number of cards of a player.
Player::Player(string name){
    this->name = name;
    this->cards_left = 0;
}

// Returns the number of cards left in the player's deck.
int Player::stacksize(){
    return this->cards_left;
}

// Returns the number of cards that the player has won.
int Player::cardesTaken(){
    return this->won_cards;
}

// Returns the name of the player.
string Player::getName(){
    return this->name;
}

// Sets the name of the player.
void Player::setName(string new_name){
    this->name = new_name;
}

// Sets the number of cards left in the player's deck.
void Player::setCardsLeft(int new_cards_left){
    this->cards_left = new_cards_left;
}

// Adds the specified number of cards to the player's won cards.
void Player::addWonCards( int add_won_cards){
    this->won_cards+=add_won_cards;
}

// Returns a vector containing the cards in the player's deck.
vector<Card> Player::getDeckOfCards(){
    return this->cards;
}

// Adds a card to the player's deck.
void Player::setCardInDeckOfCards(Card card){
    this->cards.push_back(card);
}

// Returns true if the player is currently playing and false otherwise.
bool Player::IsPlaying(){
    return this->is_playing;
}

// Sets the playing status of the player.
void Player::setIsPlaying(bool new_playing_status){
    this->is_playing = new_playing_status;
}

// Removes the last card from the player's deck and throw an exception if the deck is empty.
void Player::RemoveCardFromDeck(){
    if (this->cards.size() == 0)
    {
        throw invalid_argument("You are trying to remove from deck with no cards");
    }
    else
    {
        this->cards.pop_back();
    }
}