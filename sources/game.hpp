//
// Created by avi on 20/03/2023.
//
#ifndef CPP_EX2_GAME_HPP
#define CPP_EX2_GAME_HPP
#include "player.hpp"
#include <vector>
#include <string>
using namespace std;
namespace ariel{}
using namespace std;
namespace ariel{}

    class Game{
    private:
        Player & player1;
        Player & player2;
        vector<string> TurnStats;
        int DrawCount;
        int countCardsAddition = 0;
    public:  
        Game(Player& player1, Player& player2);
        void playTurn();
        void printLastTurn();
        void playAll ();
        void printWiner();
        void printLog();
        void printStats();
        void divide_cards_for_each_player(int num_of_cards);
        void setCountCardsAddition(int num);
        int getCountCardsAddition();
    };
#endif //CPP_EX2_GAME_HPP
