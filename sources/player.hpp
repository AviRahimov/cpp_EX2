//
// Created by avi on 20/03/2023.
//

#ifndef CPP_EX2_PLAYER_HPP
#define CPP_EX2_PLAYER_HPP

#include <string>
using namespace std;
namespace ariel{}

    class Player{
    private:
        string str;
        int cards_left, won_cards;
    public:
        Player();
        Player(string str);
        Player(string str, int cards_laft, int won_cards);
        int stacksize();
        int cardesTaken();
        string getStr();
        void setStr(string new_str);
    };
#endif //CPP_EX2_PLAYER_HPP
