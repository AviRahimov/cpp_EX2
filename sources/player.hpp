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
        bool is_playing;
    public:
        Player();
        Player(string str);
        int stacksize();
        int cardesTaken();
        string getStr();
        void setStr(string new_str);
        int getCardsLeft();
        void setCardsLeft(int new_cards_left);
        int getWonCards();
        void setWonCards( int new_won_cards);
        bool IsPlaying();
        void setIsPlaying(bool new_playing_status);
    };
#endif //CPP_EX2_PLAYER_HPP
