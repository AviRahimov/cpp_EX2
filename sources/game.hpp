//
// Created by avi on 20/03/2023.
//

#ifndef CPP_EX2_GAME_HPP
#define CPP_EX2_GAME_HPP
#include "player.hpp"

namespace ariel{}
    class Game{
    public:
        Player player1, player2;
        Game(Player player1, Player player2);
        Game();
        void playTurn();
        void printLastTurn();
        void playAll ();
        void printWiner();
        void printLog();
        void printStats();
    };
#endif //CPP_EX2_GAME_HPP
