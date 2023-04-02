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

    class Game{
    private:
        Player* player1;
        Player* player2;
    public:
        vector<string> TurnStats;
        int DrawCount;
        static int countCardsAddition;
        Game(Player& player1, Player& player2);
        void playTurn();
        void printLastTurn();
        void playAll ();
        void printWiner();
        void printLog();
        void printStats();
    };
#endif //CPP_EX2_GAME_HPP
