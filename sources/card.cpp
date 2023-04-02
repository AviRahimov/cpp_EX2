#include "card.hpp"
#include <cstdlib>
#include <ctime>
#include <random>
using namespace ariel;
using namespace std;

Card::Card(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,13);
    string types_of_cards[4] = {"Hearts", "Spades", "Diamonds", "Clubs"}; // 4 types of card
    int number_of_card = dis(gen); // random a number between 1-13
    string type = types_of_cards[rand()%4]; // random type of card

    this->number = number_of_card;
    this->type = type;
}

//Card::~Card(){
  //  delete[] types_of_cards;
//}

int Card::getNumber(){
    return this->number;
}

string Card::getType(){
    return this->type;
}