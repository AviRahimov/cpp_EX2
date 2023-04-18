// This file contains the implementation of the Card class, which represents a single card in a deck of cards.
// Include the header file that declares the Card class.
#include "card.hpp"
using namespace ariel;
using namespace std;

// Constructor that initializes the number and type of card.
Card::Card(int num, string type_of_card) : number(num), type(type_of_card){
    number = num;
    type = type_of_card;
}

// Returns the number of the card.
int Card::getNumber(){
    return this->number;
}

// Returns the type of the card.
string Card::getType(){
    return this->type;
}

// Returns true if this card is equal to the specified card(other) and returns false otherwise.
bool Card::operator==(const Card& other) const {
    return (number == other.number && type == other.type);
}