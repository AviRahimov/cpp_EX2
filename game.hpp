//
// Created by avi on 20/03/2023.
//

#ifndef CPP_EX2_GAME_HPP
#define CPP_EX2_GAME_HPP
#include "player.hpp"

class game{
private:
    Player player1, player2;
public:
    game();
    game(Player player1, Player player2);
    void playTurn();
    void printLastTurn();
    void playAll ();
    void printWiner();
    void printLog();
    void printStats();
    Player getPlayer1();
    Player getPlayer2();
    void setPlayer1(Player newPlayer1);
    void setPlayer2(Player newPlayer2);

};

#endif //CPP_EX2_GAME_HPP
