//
// Created by avi on 20/03/2023.
//

#ifndef CPP_EX2_CARD_HPP
#define CPP_EX2_CARD_HPP
#include <string>
using namespace std;
namespace ariel{}

    class Card{
    private:
        int number; // A number between 1-13
        string type; // The card type like Hearts or Spades etc.
    public:     
        Card(int num, string type_of_card);
        int getNumber();
        string getType();
        bool operator==(const Card& other) const;
    };
#endif //CPP_EX2_CARD_HPP
