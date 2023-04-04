#include "card.hpp"


using namespace ariel;
using namespace std;

Card::Card(int num, string type_of_card) : number(num), type(type_of_card){
    number = num;
    type = type_of_card;
}

int Card::getNumber(){
    return this->number;
}

string Card::getType(){
    return this->type;
}

bool Card::operator==(const Card& other) const {
    return (number == other.number && type == other.type);
}