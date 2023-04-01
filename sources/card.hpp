//
// Created by avi on 20/03/2023.
//

#ifndef CPP_EX2_CARD_HPP
#define CPP_EX2_CARD_HPP
#include <string>

namespace ariel{
    class Card{
    private:
        int number; // A number between 1-13
        string type; // The card type like Hearts or Spades etc.
    public:     
        Card(int num_of_cards);
        int getNumber(){};
//        void setNumber(int NewNumber){};
        string getType(){};
    };
}
#endif //CPP_EX2_CARD_HPP
